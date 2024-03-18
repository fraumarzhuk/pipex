/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:54:28 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 12:39:51 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_len);
}

// #include <string.h>
// #include <stdio.h>
// size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

// int main() {
//     char *src = NULL;
//     char dst2[50];
//     size_t result2;

//     // Test 1: Copy with enough space in destination
//     // result1 = ft_strlcpy(dst1, src, sizeof(dst1));
//     result2 = ft_strlcpy(dst2, src, sizeof(dst2));
//     printf("Test 1 -  strlcpy: %s, lengths: %zu\n", dst2, result2);

//     // // Test 2: Copy with limited space in destination
//     // result1 = ft_strlcpy(dst1, src, 10);
//     // result2 = strlcpy(dst2, src, 10);
//     // printf("Test 2 - ft_strlcpy: %s, strlcpy:
// %s, lengths: %zu, %zu\n", dst1, dst2, result1, result2);

//     // // Test 3: Copy with zero size
//     // result1 = ft_strlcpy(dst1, src, 0);
//     // result2 = strlcpy(dst2, src, 0);
//     // printf("Test 3 - ft_strlcpy: %s, strlcpy: %s, 
//lengths: %zu, %zu\n", dst1, dst2, result1, result2);

//     return 0;
// }