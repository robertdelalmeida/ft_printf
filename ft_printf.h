/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:43:53 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/10/25 18:13:05 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

typedef struct t_flags
{
	int		left;
	int		zero;
	char	width[10];
	char	point[10];
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_ischar(va_list new_list, char *str_format);
int		ft_isnumber(va_list new_list, char *str_format);
int		ft_isstring(va_list new_list, char *str_format);
int		ft_ispointer(va_list new_list, char *str_format);
int		ft_isunsigned(va_list new_list, char *str_format);
int		ft_search_percent(va_list new_list, char *format);
int		ft_ishexa(va_list new_list, char *str_format, char c);
int		ft_check_type(char *str, size_t len, va_list new_list);
void	ft_putptr(void *ptr);
void	ft_putnbr_fd(long n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_base(unsigned long nb);
void	ft_initialize_flags(t_flags *list);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putnbr_base_upper(unsigned long nb);
size_t	ft_nbrlen(long n);
size_t	ft_strlen(const char *str);
size_t	ft_hexa_len(unsigned long n);
size_t	ft_getwidth(char *str, t_flags *list);
size_t	ft_getprecision(char *str, t_flags *list);
size_t	ft_check_flags(char *str, t_flags list);

#endif