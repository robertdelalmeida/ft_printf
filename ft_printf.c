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
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_check_type(format, i, new_list);
			j += 2;
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return (count + i - j);
}

int	ft_check_type(char *str, int len, va_list new_list)
{
	size_t count;

	count = 0;
	if (str[len + 1] == 'c')
		count += ft_ischar(new_list, &str[len]);
	else if (str[len + 1] == 's')
		count += ft_isstring(new_list);
	else if (str[len + 1] == 'p')
		count += ft_ispointer(new_list);
	else if (str[len + 1] == 'd' || str[len + 1] == 'i')
		count += ft_isnumber(new_list);
	else if (str[len + 1] == 'u')
		count += ft_isunsigned(new_list);
	else if (str[len + 1] == 'x' || str[len + 1] == 'X')
		count += ft_ishexa(new_list, str[len + 1]);
	else {
		ft_putchar_fd('%', 1);
		count++;
	}
	return (count);
}

int	ft_ischar(va_list new_list, char *str_format)
{
	char	c;

	c = va_arg(new_list, int);
	// /ft_check_flags(str_format, c);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_isstring(va_list new_list)
{
	char	*str;
	char	*arg;

	arg = va_arg(new_list, char*);
	str = malloc(ft_strlen(arg) + 1);
	if (str == NULL)
    	return (0);
	ft_strlcpy(str, arg, ft_strlen(arg) + 1);
	ft_putstr_fd(str, 1);
	// printf("arg: %zu", ft_strlen(arg));
	return (ft_strlen(arg));
}

int	ft_ispointer(va_list new_list)
{
	void	*ptr;

	ft_putstr_fd("0x", 1);
	ptr = va_arg(new_list, void*);
	ft_putnbr_base((unsigned long)ptr);
	// ft_ptrlen((unsigned long) ptr);
	return (14);
}

int	ft_isnumber(va_list new_list)
{
	int	d;

	d = va_arg(new_list, int);
	ft_putnbr_fd(d, 1);
	// printf("d: %i", ft_nbrlen(d));
	return (ft_nbrlen(d));
}

int	ft_isunsigned(va_list new_list)
{
	unsigned int	u;

	u = va_arg(new_list, unsigned int);
	ft_putnbr_fd(u, 1);
	// printf("u: %i", ft_nbrlen(u));
	return (ft_nbrlen(u));
}

int	ft_ishexa(va_list new_list, char c)
{
	unsigned int	x_lower;
	unsigned int	x_upper;

	if (c == 'x'){
		x_lower = va_arg(new_list, int);
		ft_putnbr_base(x_lower);
		// ft_ptrlen((unsigned int) ptr)
		return (2);
	}
	else
	{
		x_upper = va_arg(new_list, int);
		ft_putnbr_base_upper(x_upper);
		return (2);
	}
}

int	main(void)
{
	char *ptr = "outubro";

	printf("\nlength: %d", ft_printf("%c %d de %s de %i %u %p %X%%", 'e', 23, ptr, 2024, (unsigned int)2147483648, &ptr, 42));
	printf("\nbarra n\n");
	printf("\nlength: %d", printf("%c %d de %s de %i %u %p %X%%", 'e', 23, ptr, 2024, (unsigned int)2147483648, &ptr, 42));
	printf("\nbarra n\n");
}
