/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_undecim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:03:43 by mzhukova          #+#    #+#             */
/*   Updated: 2024/03/11 15:00:15 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_s(char *str, unsigned int n, unsigned int len)
{
	unsigned int	i;

	i = len - 1;
	if (n == 0)
	{
		str[0] = '0';
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*convert_num(unsigned int n)
{
	char				*res;
	unsigned int		len;
	unsigned int		temp_n;

	len = 0;
	temp_n = n;
	if (n <= 0)
		len++;
	while (temp_n != 0 && temp_n != 'u')
	{
		len++;
		temp_n /= 10;
	}
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	fill_s(res, n, len);
	return (res);
}

int	to_undecim(int c)
{
	char	*res;
	int		len;

	res = convert_num(c);
	if (res)
	{
		write(1, res, ft_strlen(res));
		len = ft_strlen(res);
		free(res);
		return (len);
	}
	free(res);
	return (1);
}
