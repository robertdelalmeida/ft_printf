/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:43:53 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/10/23 16:03:12 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct t_conv
{
	unsigned int	u;
	void			*ptr;
	char			*string;
	char			c;
	int				i;
	int				d;
	int				x_lower;
	int				x_upper;
}	t_conv;

int		ft_check_type(char *str, int len, va_list new_list);
int		ft_search_percent(va_list new_list, char *format);
int		ft_ischar(va_list new_list, char *str_format);
int		ft_ishexa(va_list new_list, char c);
int		ft_isunsigned(va_list new_list);
int		ft_ispointer(va_list new_list);
int		ft_isnumber(va_list new_list);
int		ft_isstring(va_list new_list);
int		ft_nbrlen(long n);
void	ft_putnbr_base_upper(unsigned long nb);
void	ft_putnbr_base(unsigned long nb);
void	ft_putptr(void *ptr);

#endif