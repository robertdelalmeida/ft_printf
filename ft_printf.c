/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:42:52 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/10/30 10:39:11 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	new_list;
	int		count;

	if (!format)
		return (-1);
	va_start(new_list, format);
	count = ft_search_percent(new_list, (char *)format);
	va_end(new_list);
	if (count == -1)
		return (0);
	return (count);
}

size_t	ft_search_percent(va_list new_list, char *format)
{
	t_list	flags;
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = 0;
	while (format[i] != '\0')
	{
		ft_initialize_flags(&flags);
		if (format[i] == '%')
		{
			i++;
			j += ft_check_flags(&format[i], &flags);
			count += ft_check_type(format, i, new_list, &flags);
			if (format[i] == '%')
				count++;
			i += ft_jump(format, i);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return (i + count - j);
}

size_t	ft_check_type(char *str, size_t len, va_list new_list, t_list *flags)
{
	size_t	count;
	size_t	j;

	j = 0;
	while (str[len + j] != 'c' && str[len + j] != 's' && str[len + j] != 'p'
		&& str[len + j] != 'd' && str[len + j] != 'i' && str[len + j] != 'u'
		&& str[len + j] != 'x' && str[len + j] != 'X' && str[len + j] != '%')
		j++;
	count = 0;
	if (str[len + j] == 'c')
		count += ft_ischar(new_list);
	else if (str[len + j] == 's')
		count += ft_isstring(new_list);
	else if (str[len + j] == 'p')
		count += ft_ispointer(new_list, 'p');
	else if (str[len + j] == 'd' || str[len + j] == 'i')
		count += ft_isnumber(new_list, flags);
	else if (str[len + j] == 'u')
		count += ft_isunsigned(new_list);
	else if (str[len + j] == 'x' || str[len + j] == 'X')
		count += ft_ishexa(new_list, flags, str[len + j]);
	else
		ft_putchar_fd('%', 1);
	return (count);
}

size_t	ft_jump(char *str, size_t len)
{
	size_t	j;

	j = 0;
	while (str[len + j] != 'c' && str[len + j] != 's' && str[len + j] != 'p'
		&& str[len + j] != 'd' && str[len + j] != 'i' && str[len + j] != 'u'
		&& str[len + j] != 'x' && str[len + j] != 'X' && str[len + j] != '%')
		j++;
	return (j);
}

int	ft_ischar(va_list new_list)
{
	char	c;

	c = va_arg(new_list, int);
	ft_putchar_fd(c, 1);
	return (1);
}

// #include <limits.h>
// int	main(void)
// {
// 	char ch = 'A';
// 	char *str = "Caroline";
// 	int i = 456;
// 	int j = -5;
// 	unsigned int u = 5;
//     int count;
// cc -w ft_flags.c ft_printf.c ft_printf.h ft_lib.c ft_types.c ft_utils.c
//     count = 0;

// 	//Test 1: c, s, d, i
// 	printf("Test1\n");
// 	count = ft_printf("Oi, tudo bem %s? Sua sala e 7%c. Agora sao %dh %ih.\n", str, ch, i, i);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("Oi, tudo bem %s? Sua sala e 7%c. Agora sao %dh %ih.\n", str, ch, i, i);
//     printf("printf count = %d\n\n\n", count);

// 	//Test 2: p
// 	printf("Test2\n");
//     count = ft_printf("p: %p\n", str);
// 	printf("ft_printf count = %d\n\n", count);  
// 	count = printf("p: %p\n", str);
// 	printf("printf count = %d\n\n\n", count);  

// 	//Test 3: u
// 	printf("Test3\n");
//     count = ft_printf("unsigned: %u\n", u);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("unsigned: %u\n", u);
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 4: u but sending negative int
// 	printf("Test4\n");
//     count = ft_printf("unsigned: %u\n", j);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("unsigned: %u\n", j);
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 5: x
// 	printf("Test5\n");
// 	count = ft_printf("hex: %x\n", i);
// 	printf("ft_printf count = %d\n\n", count);
// 	ft_printf("hex: %x\n", i);
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 6: X
// 	printf("Test6\n");
// 	count = ft_printf("hex: %X\n", i);
// 	printf("ft_printf count = %d\n\n", count);
// 	ft_printf("hex: %X\n", i);
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 7: %%
// 	printf("Test7\n");
// 	count = ft_printf("percentage %%\n");
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("percentage %%\n");
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 8: %j - an invalid argument
// 	//compile with -w
// 	printf("Test8\n");
//     count = ft_printf("f%jk\n", i);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("f%jk\n", i);
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 9: s (null)
// 	//compile with -w
// 	//(null)
// 	//NULL is used to represent a null pointer,
// 	//a pointer that doesn't point to a valid memory address.
// 	//(void*)0)
// 	printf("Test9\n");
// 	count = ft_printf(" NULL %s NULL\n", NULL);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" NULL %s NULL\n", NULL);
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 10: s (sending 0)
// 	//compile with -w
// 	printf("Test10\n");
// 	count = ft_printf(" NULL %s NULL\n", 0);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" NULL %s NULL\n", 0);
// 	printf("printf count = %d\n\n\n", count);
	
// 	//Test 11: p (long address)
// 	//compile with -w
// 	//(long) LONG_MAX: 2147483647  LONG_MIN: -2147483648 
// 	printf("Test11\n");
// 	count = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	printf("printf count = %d\n\n\n", count);
	
// 	//Test 12: p (unsigned long address)
// 	//compile with -w
// 	//(unsigned long) 4294967295
// 	printf("Test12\n");
// 	count = ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 13: p (nil) (sending 0)
// 	//compile with -w
// 	//(nil) why not (null)????
// 	//In Objective-C (another language), nil is a pointer to a non-existent object
// 	//The use of (nil) to represent a null pointer is more common in languages like Objective-C, 
// 	//where (nil) is a literal to represent a null reference to an object.
// 	printf("Test13\n");
// 	count = ft_printf(" %p %p \n", 0, 0);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" %p %p \n", 0, 0);
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 14: hex (sending 0)
// 	printf("Test14\n");
// 	count = ft_printf(" %x %x \n", 0, 0);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" %x %x \n", 0, 0);
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 15: with no arguments
// 	//undefined behavior because printf will attempt to access arguments 
// 	//that do not exist or do not match the format specifiers.
// 	printf("Test15\n");
// 	count = ft_printf("Oi %d Olá\n");
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("Oi %d Olá\n");
// 	printf("printf count = %d\n\n\n", count);

// 	//Test 16
// 	//undefined behavior, it can lead to seg fault, crash, depending the compiler
// 	printf("Test16\n");
// 	count = printf(NULL);
// 	printf("printf count = %d\n\n", count);
// 	count = ft_printf(NULL);
// 	printf("ft_printf count = %d\n\n\n", count);

// 	//Test 17
// 	printf("Test17\n");
// 	count = printf("%s\n", "");
// 	printf("printf count = %d\n\n", count);
// 	count = ft_printf("%s\n", "");
// 	printf("ft_printf count = %d\n\n\n", count);

// }

/*
void printcmp(int a, int b)
{
    if (a == b)
    {
        ft_printf("OK\n");
    }
    else
        ft_printf("KO --!\n");
}

int main(void)
{
    char    *str = "12ozmouse";
    char    *nulo = NULL;
    char    **ptr;
    int     myfunc;
    int     original;
    ptr = &str;

    ft_printf("---------my func-----------\n");
    myfunc = ft_printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2],
     97 - 32, *str, 48);
    
    ft_printf("\n---------original-----------\n");
	original = printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2],
     97 - 32, *str, 48);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("s flag: %s|%s|%s|%s|%s|%s\n", "12ozmouse",
     str, str + 2, "", "-", nulo);
    
    ft_printf("\n---------original-----------\n");
    original = printf("s flag: %s|%s|%s|%s|%s|%s\n", "12ozmouse",
     str, str + 2, "", "-", nulo);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);
    
    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, 
	nulo, &nulo);

    ft_printf("\n---------original-----------\n");
    original = printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, 
	nulo, &nulo);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0,
     2147483647, -2147483648);

    ft_printf("\n---------original-----------\n");
    original = printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0,
     2147483647, -2147483647 - 1);

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("%% flag: %% | %%|%% \n");

    ft_printf("\n---------original-----------\n");
    original = printf("%% flag: %% | %%|%% \n");

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(", I've printed %d characters!\n",
     ft_printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));

    ft_printf("\n---------original-----------\n");
    original = printf(", I've printed %d characters!\n",
     printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(", I've printed %d characters!\n",
     ft_printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));

    ft_printf("\n---------original-----------\n");
    original = printf(", I've printed %d characters!\n",
     printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(", I've printed %d characters!\n",
     ft_printf("INT MIN: %d", -2147483647 - 1));

    ft_printf("\n---------original-----------\n");
    original = printf(", I've printed %d characters!\n",
     printf("INT MIN: %d", -2147483647 - 1));

    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], 
	nulo, str, -912387, 00000, -99, 743, 743);

    ft_printf("\n---------original-----------\n");
    original = printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], 
	nulo, str, -912387, 00000, -99, 743, 743);
    
    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);


    ft_printf("\n---------my func-----------\n");
    myfunc = ft_printf(NULL);

    ft_printf("\n---------original-----------\n");
    original = printf(NULL);
    
    ft_printf("\n---------resultado-----------\n");
    printcmp(myfunc, original);

}
*/