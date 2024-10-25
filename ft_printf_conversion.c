/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:57:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/10/25 17:53:03 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isstring(va_list new_list, char *str_format)
{
	char	*str;
	char	*arg;

	arg = va_arg(new_list, char *);
	if (arg == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	str = malloc(ft_strlen(arg) + 1);
	if (str == NULL)
		return (0);
	ft_strlcpy(str, arg, ft_strlen(arg) + 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (ft_strlen(arg));
}

int	ft_ispointer(va_list new_list, char *str_format)
{
	void	*ptr;

	ptr = va_arg(new_list, void *);
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base((unsigned long)ptr);
	return (ft_hexa_len((unsigned long) ptr) + 2);
}

int	ft_isnumber(va_list new_list, char *str_format)
{
	int	d;

	d = va_arg(new_list, int);
	ft_putnbr_fd(d, 1);
	return (ft_nbrlen(d));
}

int	ft_isunsigned(va_list new_list, char *str_format)
{
	unsigned int	u;

	u = va_arg(new_list, unsigned int);
	ft_putnbr_fd(u, 1);
	return (ft_nbrlen(u));
}

int	ft_ishexa(va_list new_list, char *str_format, char c)
{
	unsigned int	x_lower;
	unsigned int	x_upper;

	if (c == 'x')
	{
		x_lower = va_arg(new_list, int);
		ft_putnbr_base(x_lower);
		return (ft_hexa_len(x_lower));
	}
	else
	{
		x_upper = va_arg(new_list, int);
		ft_putnbr_base_upper(x_upper);
		return (ft_hexa_len(x_upper));
	}
}
