/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:03:42 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/28 16:26:55 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <strings.h>

int	to_s(char *str)
{
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
