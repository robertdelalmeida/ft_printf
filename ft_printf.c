/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:42:52 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/10/23 16:03:06 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	new_list;
	int		count;

	if (!format)
		return (0);
	va_start(new_list, format);
	count = ft_search_percent(new_list, (char *)format);
	va_end(new_list);
	return (count);
}

int	ft_search_percent(va_list new_list, char *format)
{
	size_t	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += ft_check_type(format[i + 1], new_list);
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return (i);
}

int	ft_check_type(char c, va_list new_list)
{
	t_conv *node;

	node = ft_calloc(1, sizeof(t_conv));
	if (c == 'c')
		ft_ischar(new_list, node);
	else if (c == 's')
		ft_isstring(new_list, node);
	else if (c == 'p')
		ft_ispointer(new_list, node);
	else if (c == 'd' || c == 'i')
		ft_isnumber(new_list, node);
	else if (c == 'u')
		ft_isunsigned(new_list, node);
	else if (c == 'x' || c == 'X')
		ft_ishexa(new_list, node, c);
	else
		ft_putchar_fd('%', 1);
	return (1);
}

void	ft_ischar(va_list new_list, t_conv *node)
{
	(*node).c = va_arg(new_list, int);
	ft_putchar_fd((*node).c, 1);
}

void	ft_isstring(va_list new_list, t_conv *node)
{
	(*node).string = va_arg(new_list, char*);
	ft_putstr_fd((*node).string, 1);
}

void	ft_ispointer(va_list new_list, t_conv *node)
{
	ft_putstr_fd("0x", 1);
	(*node).ptr = va_arg(new_list, void*);
	ft_putnbr_base((unsigned long)(*node).ptr);
}

void	ft_isnumber(va_list new_list, t_conv *node)
{
	(*node).d = va_arg(new_list, int);
	ft_putnbr_fd((*node).d, 1);
}

void	ft_isunsigned(va_list new_list, t_conv *node)
{
	(*node).u = va_arg(new_list, unsigned int);
	ft_putnbr_fd((*node).u, 1);
}

void	ft_ishexa(va_list new_list, t_conv *node, char c)
{
	if (c == 'x'){
		(*node).x_lower = va_arg(new_list, int);
		ft_putnbr_base((*node).x_lower);
	}
	else
	{
		(*node).x_upper = va_arg(new_list, int);
		ft_putnbr_base_upper((*node).x_upper);
	}
}

void	ft_putptr(void *ptr)
{
	write(1, ptr, 14);
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

int	main(void)
{
	char *ptr = NULL;
	unsigned int i = 2147483648;

	ft_printf("hoje %c %d de %s de %i e o int máximo negativo é: %u, to no endereço %p, chance de %X%%", 'e', 23, "outubro", 2024, i, &ptr, 42);
	ft_printf("\nbarra n\n");
	printf("hoje %c %d de %s de %i e o int máximo negativo é: %u, to no endereço %p, chance de %X%%", 'e', 23, "outubro", 2024, i, &ptr, 42);
	printf("\nbarra n\n");
}
