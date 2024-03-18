/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexuplow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:03:30 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/28 20:41:32 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int c)
{
	int	len;

	len = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		len++;
		c /= 16;
	}
	return (len);
}

int	to_hexuplow(int c, char typ)
{
	char				res[32];
	int					digit;
	int					i;
	unsigned int		temp;

	temp = (unsigned int)c;
	i = 0;
	if (temp == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (temp != 0)
	{
		digit = temp % 16;
		if (digit < 10)
			res[i++] = digit + '0';
		else
			res[i++] = (digit - 10) + typ ;
		temp /= 16;
	}
	while (i--)
		ft_putchar_fd(res[i], 1);
	return (hex_len((unsigned int)c));
}
