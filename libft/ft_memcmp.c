/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:13:19 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:42:29 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	ptr_s1 = (const unsigned char *)s1;
	ptr_s2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*ptr_s1 != *ptr_s2)
			return (*ptr_s1 - *ptr_s2);
		ptr_s1++;
		ptr_s2++;
		n--;
	}
	return (0);
}

// int main()
// {
// 	char str1[] = "A noisy noise annoys";
// 	char str2[] = "A noisy noise annoys an oyster most.";
// 	size_t len1 = 20;
// 	int  result1 = ft_memcmp(str1, str2, len1);
// 	printf("Result = %d\n", result1);
// }