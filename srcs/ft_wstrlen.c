/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:45 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 14:18:46 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len += ft_wcharlen(*str);
		str++;
	}
	return (len);
}
