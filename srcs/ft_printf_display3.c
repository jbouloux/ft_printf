/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:10:51 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 16:14:27 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptwstrflags(wchar_t *string, char *zeros, int len, int *opttab)
{
	if (opttab[0])
	{
		ft_putstr(zeros);
		ft_putwstr(string);
	}
	len = ft_wstrlen(string);
	while ((opttab[6] > len) && !opttab[2])
	{
		ft_putchar(' ');
		opttab[6]--;
		opttab[13]++;
	}
	if (!opttab[0])
	{
		ft_putstr(zeros);
		ft_putwstr(string);
	}
	opttab[13] += ft_wstrlen(string) + ft_freestrlen(zeros);
	if (opttab[14])
		free(string);
	return (opttab[13]);
}

int			ft_printwstr(va_list ap, int *opttab)
{
	wchar_t	*string;
	char	*zeros;
	int		len;
	int		n;

	opttab[14] = 0;
	zeros = ft_strnew(1);
	string = va_arg(ap, wchar_t*);
	if (!string)
	{
		zeros = ft_strredup(zeros, "(null)");
		return (ft_displaystr(zeros, opttab));
	}
	len = ft_wstrlen(string);
	n = (opttab[6] - len);
	if (opttab[9] && opttab[8] < len)
		n = (opttab[6] - opttab[8]);
	if (opttab[9] && (opttab[8] < len))
	{
		string = ft_wstrndup(string, opttab[8]);
		opttab[14] = 1;
	}
	if ((opttab[2]) && (!opttab[0]) && (opttab[6]) && (n > 0))
		zeros = ft_strredup(zeros, ft_paddingstr(n, '0'));
	return (ft_ptwstrflags(string, zeros, len, opttab));
}

int			ft_displaychar(char a, int *opttab)
{
	char	*string;
	int		len;

	len = (opttab[6] - 1);
	string = ft_strnew(1);
	string[0] = a;
	if (a == 0)
		return (ft_displaynul(opttab, string, len));
	if ((opttab[2]) && (!opttab[0]) && (opttab[6]))
		string = ft_padstr(string, len, '0');
	if (opttab[0])
		ft_putstr(string);
	while (((!opttab[2]) || (opttab[2] && opttab[0])) && (opttab[6]-- > \
		((int)ft_strlen(string) + (a == 0 ? 1 : 0))))
	{
		ft_putchar(' ');
		opttab[13]++;
	}
	if (!opttab[0])
		ft_putstr(string);
	opttab[13] += ft_freestrlen(string);
	return (opttab[13]);
}

int			ft_printc(va_list ap, int *opttab, char c)
{
	char	a;

	if (opttab[10] == 4 || c == 'C')
		return (ft_printwchar(ap, opttab));
	a = va_arg(ap, int);
	return (ft_displaychar(a, opttab));
}

int			ft_displaynul(int *opttab, char *string, int len)
{
	if ((opttab[2]) && (!opttab[0]) && (opttab[6]))
		string = ft_strredup(string, ft_paddingstr(len, '0'));
	if (opttab[0])
	{
		ft_putstr(string);
		ft_putchar(0);
	}
	while (((!opttab[2]) || (opttab[2] && opttab[0])) && (opttab[6]-- > \
		((int)ft_strlen(string) + 1)))
	{
		ft_putchar(' ');
		opttab[13]++;
	}
	if (!opttab[0])
	{
		ft_putstr(string);
		ft_putchar(0);
	}
	opttab[13] += ft_freestrlen(string) + 1;
	return (opttab[13]);
}
