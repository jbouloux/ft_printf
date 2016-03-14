/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:10:09 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 16:08:39 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	*ft_dispatch2(char *str, int *opttab)
{
	if (*str == '.')
	{
		if (ft_isdigit(*(str + 1)))
		{
			str++;
			opttab[14]++;
			opttab = ft_precision(str, opttab);
			str += opttab[9];
			opttab[14] += opttab[9];
			opttab[9]++;
		}
		else
		{
			opttab[9]++;
			str++;
			opttab[14]++;
		}
	}
	return (opttab);
}

int			*ft_dispatch(char *str, va_list ap)
{
	int *opttab;

	opttab = ft_createtab(15);
	str++;
	opttab[12]++;
	if (ft_isoption(*str))
		opttab = ft_options(str, opttab);
	str += opttab[5];
	if (ft_isdigit(*str))
		opttab = ft_minsize(str, opttab);
	str += opttab[7];
	opttab = ft_dispatch2(str, opttab);
	str += opttab[14];
	while (ft_ismodifier(str[opttab[11]]))
		opttab = ft_modifier((str + opttab[11]), opttab);
	str += opttab[11];
	if (ft_isalpha(*str) || *str == '%')
	{
		opttab[13] = ft_checktype(str, ap, opttab);
		opttab[12]++;
	}
	else
		opttab[13] = 0;
	opttab[12] += (opttab[5] + opttab[7] + opttab[9] + opttab[11]);
	return (opttab);
}

static int			ft_printfloop(va_list ap, char *str)
{
	int	result;
	int	*opttab;

	result = 0;
	while (*str)
	{
		if (*str == '%')
		{
			opttab = ft_dispatch(str, ap);
			result += opttab[13];
			str += opttab[12];
			free(opttab);
		}
		else
		{
			ft_putchar(*str);
			result++;
			str++;
		}
	}
	return (result);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	char	*str;
	char 	*tmp;

	str = ft_strdup(format);
	tmp = str;
	result = 0;
	va_start(ap, format);
	result = ft_printfloop(ap, str);
	va_end(ap);
	free(tmp);
	return (result);
}
