/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:13:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/26 12:13:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_flags(t_flags *list)
{
	(*list).left = 0;
	(*list).zero = 0;
	ft_memset((*list).width, 0, 10);
	ft_memset((*list).point, 0, 10);
}

size_t	ft_check_flags(char *s, t_flags list)
{
	int		flag;
	size_t	j;

	j = 0;
	flag = 0;
	while (++j, s[j] && s[j] != 'c' && s[j] != 's' && s[j] != 'p' && s[j] != 'd'
		&& s[j] != 'i' && s[j] != 'u' && s[j] != 'x' && s[j] != 'X'
		&& s[j] != '%')
	{
		if (s[j] == '-')
			list.left = 1;
		else if (s[j] == '0' && list.left != 1 && !flag)
			list.zero = 1;
		else if (s[j] == '.')
		{
			j += ft_getprecision(&s[j], &list);
			flag = 1;
		}
		else if (s[j] >= '1' && s[j] <= '9')
		{
			j += ft_getwidth(&s[j], &list);
			flag = 1;
		}
	}
	return (j);
}

size_t	ft_getprecision(char *str, t_flags *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (str[j] >= '0' && str[j] <= '9')
	{
		(*list).point[i] = str[j];
		j++;
		i++;
	}
	(*list).point[i] = '\0';
	return (j);
}

size_t	ft_getwidth(char *str, t_flags *list)
{
	size_t	w;
	size_t	j;

	w = 0;
	j = 0;
	while (str[j] >= '0' && str[j] <= '9')
	{
		(*list).width[w] = str[j];
		w++;
		j++;
	}
	(*list).width[w] = '\0';
	return (j - 1);
}

// int main()
// {
// 	int ft = 0;
// 	ft = ft_printf("this is ft %-010.05d|", 42);

// 	ft_printf("\n");
// 	ft_printf("len: %d\n", ft);
// 	printf("len: %d\n", printf("this is tf %-010.05d|", 42));
// }