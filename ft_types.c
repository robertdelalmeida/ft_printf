/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:57:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/11/01 12:44:07 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isstring(va_list new_list)
{
	char	*arg;

	arg = va_arg(new_list, char *);
	if (arg == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg));
}

int	ft_ispointer(va_list new_list, char c)
{
	void	*ptr;

	ptr = va_arg(new_list, void *);
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base((unsigned long)ptr, c);
	return (ft_hexa_len((unsigned long) ptr) + 2);
}

int	ft_isnumber(va_list new_list)
{
	int	d;

	d = va_arg(new_list, int);
	ft_putnbr_fd(d, 1);
	return (ft_nbrlen(d));
}

int	ft_isunsigned(va_list new_list)
{
	unsigned int	u;

	u = va_arg(new_list, unsigned int);
	ft_putnbr_fd(u, 1);
	return (ft_nbrlen(u));
}

int	ft_ishexa(va_list new_list, char c)
{
	unsigned int	x;

	x = va_arg(new_list, int);
	if (c == 'x')
		ft_putnbr_base(x, c);
	else
		ft_putnbr_base(x, c);
	return (ft_hexa_len(x));
}
