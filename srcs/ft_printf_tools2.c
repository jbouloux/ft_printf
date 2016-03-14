/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:12:35 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:42:42 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_paddingstr(int len, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(len);
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

char	*ft_padstr(char *str, int len, char c)
{
	char	*pad;
	char	*tmp;
	int		i;

	i = 0;
	pad = ft_strnew(len);
	while (i < len)
	{
		pad[i] = c;
		i++;
	}
	tmp = ft_strjoin(pad, str);
	free(pad);
	free(str);
	return (tmp);
}

char *ft_strredup(char *orig, char *str)
{
	char *tmp;

	tmp = ft_strdup(str);
	free(orig);
	return (tmp);
}

char *ft_strrejoin(char *orig, char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	if (orig)
		free(orig);
	return (tmp);
}

size_t	ft_freestrlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	free(s);
	return (i);
}