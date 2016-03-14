/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:27:56 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:50:58 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	tmp = s;
	while (n > 0)
	{
		tmp[i] = '\0';
		i++;
		n--;
	}
}

char		*ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
