/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:10:31 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 16:01:37 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printoflgs(char *str, char c, int len, int *opttab)
{
	if ((size_t)opttab[8] > ft_strlen(str))
		str = ft_padstr(str, len, '0');
	if (opttab[0])
		ft_putstr(str);
	while ((size_t)opttab[6]-- > (ft_strlen(str)))
	{
		ft_putchar(c);
		opttab[13]++;
	}
	if (!opttab[0])
		ft_putstr(str);
	opttab[13] += ft_freestrlen(str);
	return (opttab[13]);
}

int			ft_printo(va_list ap, int *opttab, char u)
{
	char				*str;
	char				c;
	unsigned long long	n;
	int					len;

	c = ' ';
	if (opttab[2])
		c = opttab[0] ? ' ' : '0';
	n = ft_conv_uns(va_arg(ap, unsigned long long int), opttab, ft_isupper(u));
	str = ft_ulongtooctal(n);
	if ((opttab[9]) && (opttab[8] == 0) && (n == 0) && !opttab[4])
		str = ft_strredup(str, "");
	if (opttab[4])
		str = n > 0 ? ft_strrejoin(str, "0", str) : str;
	len = opttab[8] - (int)ft_strlen(str);
	return (ft_printoflgs(str, c, len, opttab));
}

static int	ft_ptxflgs(char *string, int *opttab, char c, int len)
{
	if (opttab[2])
	{
		if (opttab[4])
		{
			ft_putstr(c == 'x' ? "0x" : "0X");
			opttab[13] += 2;
		}
		while (opttab[2] && !opttab[0] && opttab[6]-- > len)
		{
			ft_putchar('0');
			opttab[13]++;
		}
		ft_putstr(string);
	}
	if (opttab[0] && !opttab[2])
		ft_putstr(string);
	while ((!opttab[2] || (opttab[2] && opttab[0])) && (opttab[6]-- > len))
	{
		ft_putchar(' ');
		opttab[13]++;
	}
	if (!opttab[0] && !opttab[2])
		ft_putstr(string);
	opttab[13] += ft_freestrlen(string);
	return (opttab[13]);
}

int			ft_printx(va_list ap, int *opttab, char c)
{
	unsigned long long int	n;
	int						len;
	char					*string;

	n = ft_conv_uns(va_arg(ap, unsigned long long), opttab, 0);
	string = ft_inttohexa(n);
	string = n == 0 ? ft_strredup(string, "0") : string;
	string = n == 1 ? ft_strredup(string, "1") : string;
	if ((opttab[9]) && (opttab[8] == 0) && (n == 0))
		string = ft_strredup(string, "");
	len = opttab[8] - (int)ft_strlen(string);
	if ((opttab[8] > (int)ft_strlen(string)) && (len > 0))
		string = ft_padstr(string, len, '0');
	len = ft_strlen(string) + (opttab[4] * 2);
	if (opttab[4] && !opttab[2] && n != 0)
		string = ft_strrejoin(string, "0x", string);
	if (c == 'X')
		string = ft_mintomaj(string);
	return (ft_ptxflgs(string, opttab, c, len));
}

int			ft_printmod(int *opttab)
{
	char c;

	if (opttab[2] && !opttab[0])
		c = '0';
	else
		c = ' ';
	if (opttab[0])
		ft_putchar('%');
	while (opttab[6]-- > 1)
	{
		ft_putchar(c);
		opttab[13]++;
	}
	if (!opttab[0])
		ft_putchar('%');
	return (opttab[13] + 1);
}
