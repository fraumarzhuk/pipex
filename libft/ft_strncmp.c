/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:58:25 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:44:38 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && n > 0)
	{
		if (n == 1 || *s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int main() {
//     char str1[] = "A noisy noise annoys an oyster most.";
//     char str2[] = "bonjour";
//     int result = ft_strncmp(str1, str2, 4);
//     if (result < 0) {
//         printf("str1 is less than str2\n");
//     } else if (result > 0) {
//         printf("str1 is greater than str2\n");
//     } else {
//         printf("str1 is equal to str2\n");
//     }
//     return (0);
// }