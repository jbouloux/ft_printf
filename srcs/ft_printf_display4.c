/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:11:00 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:57:44 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptpflgs(char *string, int len, int *opttab)
{
	if (opttab[8] > (int)ft_strlen(string))
		string = ft_padstr(string, len, '0');
	string = ft_strrejoin(string, "0x", string);
	if (opttab[0])
		ft_putstr(string);
	while (((!opttab[2]) || (opttab[2] && opttab[0])) && \
		(size_t)opttab[6]-- > (ft_strlen(string)))
	{
		ft_putchar(' ');
		opttab[13]++;
	}
	if (!opttab[0])
		ft_putstr(string);
	opttab[13] += ft_freestrlen(string);
	return (opttab[13]);
}

int			ft_printp(va_list ap, int *opttab)
{
	char	*string;
	void	*ptr;
	int		len;
	char	*tmp;

	ptr = va_arg(ap, void*);
	string = !ptr ? ft_strdup("0x0") : ft_adrtostr(ptr);
	tmp = string;
	string += 2;
	string = ft_strdup(string);
	free(tmp);
	if ((opttab[9]) && (opttab[8] == 0) && (!ptr))
		string = ft_strredup(string, "");
	len = (opttab[6]) - ((int)ft_strlen(string) + 2);
	if ((opttab[2]) && (!opttab[8]) && (!opttab[0]) && (len > 0))
		string = ft_padstr(string, len, '0');
	len = opttab[8] - (int)ft_strlen(string);
	return (ft_ptpflgs(string, len, opttab));
}

int			ft_displaystr(char *string, int *opttab)
{
	int		len;
	char	c;

	c = ' ';
	if (opttab[2] && !opttab[0])
		c = opttab[2] ? '0' : ' ';
	len = (opttab[6] - ft_strlen(string));
	if (opttab[9] && (opttab[8] < (int)ft_strlen(string)))
		string = ft_strndup(string, opttab[8]);
	if ((opttab[2]) && (!opttab[0]) && (opttab[6]))
		string = ft_padstr(string, len, '0');
	if (opttab[0])
		ft_putstr(string);
	while ((size_t)opttab[6] > (ft_strlen(string)))
	{
		ft_putchar(c);
		opttab[6]--;
		opttab[13]++;
	}
	if (!opttab[0])
		ft_putstr(string);
	opttab[13] += ft_freestrlen(string);
	return (opttab[13]);
}

int			ft_prints(va_list ap, int *opttab, char c)
{
	char	*tmp;
	char	*string;	

	if (opttab[10] == 4 || c == 'S')
		return (ft_printwstr(ap, opttab));
	tmp = va_arg(ap, char *);
	if ((tmp == '\0' || !tmp) && !opttab[2])
		string = ft_strdup("(null)");
	else if ((tmp == '\0' || !tmp) && opttab[2])
		string = ft_strdup("");
	else
		string = ft_strdup(tmp);
	return (ft_displaystr(string, opttab));
}
