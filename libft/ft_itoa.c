/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:56:47 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:05:09 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>
// #include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	fill_string(char *str, int n, int len)
{
	int	i;

	i = len - 1;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
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

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		temp_n;

	len = 0;
	temp_n = n;
	if (n <= 0)
		len++;
	while (temp_n != 0)
	{
		len++;
		temp_n /= 10;
	}
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == INT_MIN)
		return (ft_memcpy(res, "-2147483648", len + 1));
	fill_string(res, n, len);
	return (res);
}
// char	*allocate_mem(int n)
// {
// 	size_t	len;
// 	char	*res;
// 	int		k;

// 	len = 0;
// 	k = n;
// 	if (k <= 0)
// 	{
// 		len++;
// 		k = -k;
// 	}
// 	while (k > 0)
// 	{
// 		k /= 10;
// 		len++;
// 	}
// 	res = malloc((len + 1) * sizeof(char));
// 	if (!res)
// 		return (NULL);
// 	res[len] = '\0';
// 	return (res);
// }

// char	*reverse_arr(char *r)
// {
// 	size_t	i;
// 	size_t	len;
// 	char	temp;

// 	len = ft_strlen(r);
// 	if (r[0] == '-')
// 		i = 1;
// 	else
// 		i = 0;
// 	while (i < len)
// 	{
// 		temp = r[i];
// 		r[i] = r[len - 1];
// 		r[len - 1] = temp;
// 		i++;
// 		len--;
// 	}
// 	return (r);
// }

// char	*ft_itoa(int n)
// {
// 	char	*res;
// 	int		i;

// 	i = 0;
// 	res = allocate_mem(n);
// 	if (n == 0)
// 		*res = '0';
// 	if (n == INT_MIN)
// 		return (ft_strdup("-2147483648"));
// 	if (n < 0)
// 	{
// 		res[i] = '-';
// 		i++;
// 		n = -n;
// 	}
// 	while (n > 0)
// 	{
// 		res[i] = (n % 10) + '0';
// 		n = (n - (n % 10)) / 10;
// 		i++;
// 	}
// 	res = reverse_arr(res);
// 	return (res);
// }

// #include <stdio.h>

// int main (void)
// {
// 	printf("Result: %s \n", ft_itoa(-2147483648));
// 	printf("Result: %s \n", ft_itoa(-2456788));
// 	printf("Result: %s \n", ft_itoa(2147483647));
// 	printf("Result: %s \n", ft_itoa(0));

// 	return (0);
// }