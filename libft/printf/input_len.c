/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:23:10 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/28 15:07:31 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	input_len(int input)
{
	int	i;
	int	len;

	len = 0;
	i = input;
	if (input == -2147483648)
		return (11);
	if (input == 0)
		return (1);
	if (i < 0)
	{
		len++;
		i *= -1;
	}
	while (i > 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}
