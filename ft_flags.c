/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:13:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/28 18:56:22 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_flags(t_list *flags)
{
	(*flags).sign = 0;
	(*flags).space = 0;
	(*flags).hash = 0;
}

size_t	ft_check_flags(char *s, t_list *flags)
{
	int		flag;
	size_t	j;

	j = 0;
	flag = 0;
	while (s[j] && s[j] != 'c' && s[j] != 's' && s[j] != 'p' && s[j] != 'd'
		&& s[j] != 'i' && s[j] != 'u' && s[j] != 'x' && s[j] != 'X'
		&& s[j] != '%')
	{
		if (s[j] == ' ')
			(*flags).space = 1;
		else if (s[j] == '+')
			(*flags).sign = 1;
		else if (s[j] == '#')
			(*flags).hash = 1;
		j++;
	}
	return (j + 2);
}

// int main()
// {
// 	ft_printf("length: %d\n", ft_printf(" %%%%%% "));
// 	ft_printf("\n\n");
// 	printf("length: %d\n", printf(" %%%%%% "));
// }

	// space with s
	// TEST(2, print(" % 1s", ""));
	// TEST(3, print("% 1s ", ""));

	// # with x and X
	// TEST(1, print(" %x ", 0));
	// TEST(25, print(" %x ", LONG_MIN));
	// TEST(29, print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
