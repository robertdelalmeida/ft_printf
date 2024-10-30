/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:13:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 10:40:04 by rdel-fra         ###   ########.fr       */
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
	size_t	flag;
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

// int	ft_validation(char *s, t_list flags)
// {
// 	size_t	c;
// 	c = 0;
// 	if (s[c] == 'c' && (flags.space == 1 || flags.sign == 1
//		|| flags.hash == 1))
// 		return (0);
// 	else if (s[c] == 's' && (flags.space == 1 || flags.sign == 1
//		|| flags.hash == 1))
// 		return (0);
// 	return (1);
// }
// int main()
// {
// 	ft_printf("length: %d\n", ft_printf(" % 1s", ""));
// 	ft_printf("\n\n");
// 	printf("length: %d\n", printf(" % 1s", ""));
// }