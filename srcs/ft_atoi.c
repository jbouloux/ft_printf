/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:18:19 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:55:17 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isescaped(int c)
{
	if (c == '\a' || c == '\b' || c == '\f' || c == '\n' || c == '\r'
	|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int	result;
	int	isneg;

	result = 0;
	isneg = 0;
	while (*str == ' ' || ft_isescaped(*str))
		str++;
	if (*str == '-' || *str == '+')
		isneg = (*(str++) == '-') ? 1 : 0;
	while (*str && ft_isdigit(*str))
		result = result * 10 + (*(str++) - 48);
	return (isneg ? result * -1 : result);
}
