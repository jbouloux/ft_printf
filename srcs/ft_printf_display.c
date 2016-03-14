/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:10:24 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 16:10:03 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printwchar(va_list ap, int *opttab)
{
	int nb;

	if (opttab[0])
		nb = ft_putwchar((wchar_t)va_arg(ap, wchar_t));
	while (opttab[6] > 1)
	{
		ft_putchar(' ');
		opttab[6]--;
		opttab[13]++;
	}
	if (!opttab[0])
		nb = ft_putwchar((wchar_t)va_arg(ap, wchar_t));
	return (opttab[13] + nb);
}

static int	ft_printiflags(char *string, int *opttab, long long int n)
{
	if (opttab[1] || n < 0)
		string = n < 0 ? ft_strrejoin(string, "-", string) : ft_strrejoin(string, "+", string);
	if (opttab[3] && !opttab[1])
		string = ft_strrejoin(string, " ", string);
	if (opttab[0])
		ft_putstr(string);
	while (((!opttab[2]) || (opttab[2] && opttab[0])) && \
		((size_t)opttab[6]-- > (ft_strlen(string))))
	{
		ft_putchar(' ');
		opttab[13]++;
	}
	if (!opttab[0])
		ft_putstr(string);
	opttab[13] += ft_freestrlen(string);
	return (opttab[13]);
}

int			ft_printi(va_list ap, int *opttab, char u)
{
	char			*string;
	long long int	n;
	int				len;

	n = va_arg(ap, long long int);
	n = ft_conv_int(n, opttab, ft_isupper(u));
	string = n == LLONG_MIN ? ft_strdup("-9223372036854775808") : ft_litoa(n);
	string = n < 0 ? ft_strredup(string, string + 1) : string;
	if (!opttab[1])
		opttab[1] = n < 0 ? 1 : 0;
	opttab[2] = opttab[9] ? 0 : opttab[2];
	if ((opttab[9]) && (opttab[8] == 0) && (n == 0))
		string = ft_strredup(string, "");
	len = (opttab[6]) - ((int)ft_strlen(string) + opttab[1] + opttab[3]);
	if ((opttab[2]) && (!opttab[9]) && (!opttab[0]) && (len > 0))
		string = ft_padstr(string, len, '0');
	len = opttab[8] - (int)ft_strlen(string);
	if ((opttab[8] > (int)ft_strlen(string)) && (len > 0))
		string = ft_padstr(string, len, '0');
	return (ft_printiflags(string, opttab, n));
}

static int	ft_printuflags(char *string, int *opttab)
{
	if (opttab[0])
		ft_putstr(string);
	while (((!opttab[2]) || (opttab[2] && opttab[0])) && \
		((size_t)opttab[6]-- > (ft_strlen(string))))
	{
		ft_putchar(' ');
		opttab[13]++;
	}
	if (!opttab[0])
		ft_putstr(string);
	opttab[13] += ft_freestrlen(string);
	return (opttab[13]);
}

int			ft_printu(va_list ap, int *opttab, char u)
{
	char					*string;
	unsigned long long int	n;
	int						len;

	n = va_arg(ap, unsigned long long int);
	n = ft_conv_uns(n, opttab, ft_isupper(u));
	string = ft_ulitoa(n);
	opttab[2] = opttab[9] ? 0 : opttab[2];
	if ((opttab[9]) && (opttab[8] == 0) && (n == 0))
		string = ft_strredup(string, "");
	if ((opttab[2]) && (!opttab[9]) && (!opttab[0]) && (opttab[6]))
	{
		len = (opttab[6]) - ((int)ft_strlen(string) + opttab[1]);
		string = ft_padstr(string, len, '0');
	}
	if (opttab[8] > (int)ft_strlen(string))
	{
		len = opttab[8] - (int)ft_strlen(string);
		string = ft_padstr(string, len, '0');
	}
	return (ft_printuflags(string, opttab));
}
