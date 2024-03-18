/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:28:15 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/21 17:01:57 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	to_string(const char *s, va_list *args)
{
	if (*s == 'c')
		return (to_char(va_arg(*args, int)));
	if (*s == 's')
		return (to_s(va_arg(*args, char *)));
	if (*s == 'p')
		return (to_hex(va_arg(*args, unsigned long long)));
	if (*s == 'd' || *s == 'i')
		return (to_int((int)va_arg(*args, int)));
	if (*s == 'u')
		return (to_undecim(va_arg(*args, int)));
	if (*s == 'x')
		return (to_hexuplow(va_arg(*args, int), 'a'));
	if (*s == 'X')
		return (to_hexuplow(va_arg(*args, int), 'A'));
	if (*s == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		pr_chars;

	va_start(args, s);
	pr_chars = 0;
	while (*s != '\0')
	{
		if (*s != '%')
		{
			ft_putchar_fd(*s, 1);
			pr_chars++;
		}
		else
		{
			s++;
			pr_chars += to_string(s, &args);
		}
		s++;
	}
	va_end(args);
	return (pr_chars);
}

// #include <stdio.h>
// int main()
// {
// 	// char *test = "Hello";
// 	// char *p = test;
// 	printf("💀Please work💀\n\n✨Unsigned integers:\n");
// 	unsigned int i = -2147483648u;
// 	printf("Printfres: %u\n", i);
// 	ft_printf("My res: %u\n\n", i);

// 	printf("✨Chars:\n");
// 	printf(":%d\n", printf("Printfres: %c", '0' +250));
// 	printf(":%d\n\n", ft_printf("My res: %c", '0' +250));

// 	printf("✨Strings:\n");
// 	printf("Printfres: %s\n", NULL);
// 	ft_printf("My res: %s\n\n", NULL);
// 	printf("Printfres: %c %c %c \n", '0', 0, '1');
// 	ft_printf("My res: %c %c %c \n", '0', 0, '1');

// 	printf("✨Ints:\n");
// 	printf("Printfres: %i\n", -45678765);
// 	ft_printf("My res: %i\n\n", -45678765);

// 	printf("✨Decimals:\n");
// 	printf("Printfres: %d\n", 45678765);
// 	ft_printf("My res: %d\n\n", 45678765);

// 	printf("✨HEXS:\n");
// 	printf("Printfres: %x\n", -57007);
// 	ft_printf("My res: %x\n", -57007);
// 	printf("Printfres: %X\n", 57007);
// 	ft_printf("My res: %X\n\n", 57007);

// 	printf("✨Pointers:\n");
// 	printf("Printfres: %p\n", (void *)14523);
// 	ft_printf("My res: %p\n\n", (void *)14523);
// 	// printf("Printfres: %p\n", 0);
// 	// ft_printf("My res: %p\n\n", 0);

// }