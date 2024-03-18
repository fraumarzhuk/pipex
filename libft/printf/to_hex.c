/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:03:25 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/28 20:09:50 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_leng(unsigned long long c)
{
	int	len;

	len = 2;
	if (c == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	while (c != 0)
	{
		len++;
		c /= 16;
	}
	return (len);
}

int	to_hex(unsigned long long input)
{
	char					res[32];
	int						digit;
	int						i;
	unsigned long long		temp;

	temp = 0;
	temp = input;
	i = 0;
	if (temp > 0)
	{
		while (temp > 0)
		{
			digit = temp % 16;
			if (digit < 10)
				res[i++] = digit + '0';
			else
				res[i++] = (digit - 10) + 'a' ;
			temp /= 16;
		}
		res[i] = '\0';
		write(1, "0x", 2);
		while (i--)
			ft_putchar_fd(res[i], 1);
	}
	return (hex_leng(input));
}
