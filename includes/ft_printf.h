/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:19:16 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:41:11 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>
# include <limits.h>

void				ft_putwstr(wchar_t const *str);
int					ft_putwchar(wchar_t c);
char				*ft_mintomaj(char *str);
void				ft_putnbr(int n);
char				*ft_strnew(size_t size);
int					ft_unsintlen(unsigned long n);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strndup(char *s1, size_t n);
wchar_t				*ft_wstrndup(wchar_t *s1, int n);
int					ft_putunsint(unsigned int n);
void				ft_putstr(char const *s);
int					ft_putlong(long n);
void				ft_putchar(char c);
int					ft_longlen(unsigned long n);
char				*ft_litoa(long long int n);
char				*ft_ulitoa(unsigned long long n);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
char				*ft_ulongtooctal (unsigned long long n);
char				*ft_inttohexa(unsigned long long n);
int					ft_atoi(const char *str);
char				*ft_adrtostr (void const *p);
int					ft_printf(const char *format, ...);
int					*ft_dispatch(char *str, va_list ap);
int					ft_isoption(char c);
int					ft_ismodifier(char c);
int					ft_checktype (char *str, va_list ap, int *opttab);
int					*ft_options(char *str, int *opttab);
int					*ft_createtab (int n);
int					*ft_minsize(char *str, int *opttab);
int					*ft_precision(char *str, int *opttab);
int					*ft_modifier(char *str, int *opttab);
int					ft_prints(va_list ap, int *opttab, char c);
int					ft_displaystr(char *string, int *opttab);
int					ft_printp(va_list ap, int *opttab);
int					ft_printi(va_list ap, int *opttab, char u);
int					ft_printu(va_list ap, int *opttab, char u);
int					ft_printc(va_list ap, int *opttab, char c);
int					ft_displaychar(char a, int *opttab);
int					ft_displaynul(int *opttab, char *string, int len);
int					ft_printo(va_list ap, int *opttab, char u);
int					ft_printx(va_list ap, int *opttab, char c);
int					ft_printmod(int *opttab);
int					ft_printwchar(va_list ap, int *opttab);
int					ft_printwstr(va_list ap, int *opttab);
long long int		ft_conv_int(long long int n, int *opttab, int maj);
unsigned long long	ft_conv_uns(unsigned long long n, int *opttab, int maj);
char				*base_octal(unsigned long long int n);
int					ft_isupper(int c);
int					ft_wcharlen(wchar_t wchar);
int					ft_wstrlen(wchar_t *str);
char				*ft_paddingstr(int len, char c);
char				*ft_padstr(char *str, int len, char c);
char 				*ft_strredup(char *orig, char *str);
char 				*ft_strrejoin(char *orig, char *s1, char *s2);
size_t				ft_freestrlen(char *s);
wchar_t				*ft_wstrnew(int size);
#endif
