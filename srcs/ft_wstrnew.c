#include "ft_printf.h"

wchar_t	*ft_wstrnew(int size)
{
	wchar_t	*str;
	int		i;

	if (!(str = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size + 1)
		str[i++] = '\0';
	return (str);
}