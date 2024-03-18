/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:41:33 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:42:42 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_arr;
	unsigned char	*dst_arr;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	src_arr = (unsigned char *) src;
	dst_arr = (unsigned char *) dst;
	i = 0;
	while (n-- > 0)
	{
		dst_arr[i] = src_arr[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// 	char str2[] = "bonjour";
// 	char str1[20];
// 	size_t len = 7;
// 	ft_memcpy(str1, str2, len * sizeof(char));
// 	printf("Copied string is: %s\n", str2);
// }