/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:57:46 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/10/28 15:33:10 by rdel-fra         ###   ########.fr       */
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

int	ft_ispointer(va_list new_list)
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

int	ft_isnumber(va_list new_list, t_list *flags)
{
	int	d;
	int	sign_count;
	int	space_count;

	sign_count = 0;
	space_count = 0;
	d = va_arg(new_list, int);
	if ((*flags).sign == 1 && d > -1)
		ft_putchar_fd('+', 1);
	else if ((*flags).space == 1 && d > -1)
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(d, 1);
	if ((*flags).sign == 1 && d > -1)
		sign_count = 1;
	else if ((*flags).space == 1 && d > -1)
		space_count = 1;
	return (ft_nbrlen(d) + sign_count + space_count);
}

int	ft_isunsigned(va_list new_list)
{
	unsigned int	u;

	u = va_arg(new_list, unsigned int);
	ft_putnbr_fd(u, 1);
	return (ft_nbrlen(u));
}

int	ft_ishexa(va_list new_list, t_list *flags, char c)
{
	unsigned int	x;
	int				hash_count;

	hash_count = 0;
	x = va_arg(new_list, int);
	if (c == 'x')
	{
		if ((*flags).hash == 1)
			ft_putstr_fd("0x", 1);
		ft_putnbr_base(x);
	}
	else
	{
		if ((*flags).hash == 1)
			ft_putstr_fd("0X", 1);
		ft_putnbr_base_upper(x);
	}
	if ((*flags).hash == 1)
		hash_count = 2;
	return (ft_hexa_len(x) + hash_count);
}
