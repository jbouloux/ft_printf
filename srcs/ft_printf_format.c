/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:11:10 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 16:06:38 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checktype(char *str, va_list ap, int *opttab)
{
	int result;

	result = 0;
	if (*str == '%')
		result = ft_printmod(opttab);
	else if (*str == 's' || *str == 'S')
		result = ft_prints(ap, opttab, *str);
	else if (*str == 'p')
		result = ft_printp(ap, opttab);
	else if (*str == 'd' || *str == 'D' || *str == 'i')
		result = ft_printi(ap, opttab, *str);
	else if (*str == 'u' || *str == 'U')
		result = ft_printu(ap, opttab, *str);
	else if (*str == 'c' || *str == 'C')
		result = ft_printc(ap, opttab, *str);
	else if (*str == 'o' || *str == 'O')
		result = ft_printo(ap, opttab, *str);
	else if (*str == 'x' || *str == 'X')
		result = ft_printx(ap, opttab, *str);
	else
		result = ft_displaychar(*str, opttab);
	return (result);
}

int	*ft_options(char *str, int *opttab)
{
	while (ft_isoption(*str))
	{
		if (*str == '-')
			opttab[0] = 1;
		if (*str == '+')
			opttab[1] = 1;
		if (*str == '0')
			opttab[2] = 1;
		if (*str == ' ')
			opttab[3] = 1;
		if (*str == '#')
			opttab[4] = 1;
		str++;
		opttab[5]++;
	}
	return (opttab);
}

int	*ft_minsize(char *str, int *opttab)
{
	char	size[10];
	int		i;

	i = 0;
	while (ft_isdigit(*str))
	{
		opttab[7]++;
		str++;
	}
	str -= opttab[7];
	while (i != opttab[7])
	{
		size[i] = *str;
		str++;
		i++;
	}
	size[opttab[7]] = '\0';
	opttab[6] = ft_atoi(size);
	return (opttab);
}

int	*ft_precision(char *str, int *opttab)
{
	char	size[10];
	int		i;

	i = 0;
	while (ft_isdigit(*str))
	{
		opttab[9]++;
		str++;
	}
	str -= opttab[9];
	while (i != opttab[9])
	{
		size[i] = *str;
		str++;
		i++;
	}
	size[opttab[9]] = '\0';
	opttab[8] = ft_atoi(size);
	return (opttab);
}

int	*ft_modifier(char *str, int *opttab)
{
	if (*str == 'h')
		opttab[10] = (*(str + 1) == 'h' ? 1 : 2);
	if (*str == 'l')
		opttab[10] = (*(str + 1) == 'l' ? 3 : 4);
	if (*str == 'j')
		opttab[10] = 5;
	if (*str == 'z')
		opttab[10] = 6;
	if (opttab[10] == 1 || opttab[10] == 3)
		opttab[11] += 2;
	else
		opttab[11] += 1;
	return (opttab);
}
