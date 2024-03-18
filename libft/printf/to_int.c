/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:14:26 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/28 16:07:55 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	to_int(int input)
{
	char	*s;

	s = ft_itoa(input);
	ft_putstr_fd(s, 1);
	free(s);
	return (input_len(input));
}
