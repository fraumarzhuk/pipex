/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:59:20 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:42:54 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_arr;
	unsigned char	*src_arr;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest_arr = (unsigned char *) dest;
	src_arr = (unsigned char *) src;
	if (dest > src)
	{
		while (len--)
			dest_arr[len] = src_arr[len];
	}
	else
	{
		while (i < len)
		{
			dest_arr[i] = src_arr[i];
			i++;
		}
	}
	return (dest);
}

// int main()
// {
// 	char str2[] = "bonjour";
// 	char str1[20];
// 	size_t len = 7;
// 	ft_memmove(str1, str2, len);
// 	printf("Moved string is: %s\n", str2);
// }