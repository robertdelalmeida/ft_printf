/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:42:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 12:42:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putptr(void *ptr)
{
	write(1, ptr, 14);
}

int	ft_nbrlen(long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_base(unsigned long nb)
{
	if (nb > 15)
	{
		ft_putnbr_base(nb / 16);
		ft_putnbr_base(nb % 16);
	}
	else
	{
		if (nb >= 10)
			ft_putchar_fd(nb - 10 + 'a', 1);
		else
			ft_putchar_fd(nb + '0', 1);
	}
}

void	ft_putnbr_base_upper(unsigned long nb)
{
	if (nb > 15)
	{
		ft_putnbr_base_upper(nb / 16);
		ft_putnbr_base_upper(nb % 16);
	}
	else
	{
		if (nb >= 10)
			ft_putchar_fd(nb - 10 + 'A', 1);
		else
			ft_putchar_fd(nb + '0', 1);
	}
}
