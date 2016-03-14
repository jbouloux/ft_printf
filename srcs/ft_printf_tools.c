/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:11:23 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:50:18 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_isoption(char c)
{
	if (c == '-' || c == '+' || c == '#' || c == '0' \
		|| c == ' ')
		return (1);
	else
		return (0);
}

int					ft_ismodifier(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	else
		return (0);
}

int					*ft_createtab(int n)
{
	int i;
	int *tab;

	tab = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i <= n - 1)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

long long int		ft_conv_int(long long int n, int *opttab, int maj)
{
	long long int a;

	if (opttab[10] == 4 || opttab[10] == 5 || opttab[10] == 6 || maj > 0)
		a = (long)n;
	else if (opttab[10] == 1)
		a = (signed char)n;
	else if (opttab[10] == 2)
		a = (short int)n;
	else if (opttab[10] == 0)
		a = (int)n;
	else if (opttab[10] == 3)
		a = (long long)n;
	else
		a = n;
	return (a);
}

unsigned long long	ft_conv_uns(unsigned long long n, int *opttab, int maj)
{
	long long int a;

	if (opttab[10] == 4 || opttab[10] == 5 || opttab[10] == 6 || maj > 0)
		a = (unsigned long)n;
	else if (opttab[10] == 1)
		a = (unsigned char)n;
	else if (opttab[10] == 2)
		a = (unsigned short int)n;
	else if (opttab[10] == 0)
		a = (unsigned int)n;
	else
		a = n;
	return (a);
}
