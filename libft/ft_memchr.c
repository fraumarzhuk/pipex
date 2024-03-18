/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:48:02 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:42:18 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*char_ptr;

	char_ptr = (const char *)s;
	while (n > 0)
	{
		if ((unsigned char)*char_ptr == (unsigned char)c)
			return ((void *)char_ptr);
		char_ptr++;
		n--;
	}
	return (NULL);
}

// int main()
// {
//     char array[60] = "A noisy noise annoys an oyster most.";
//     int c = 'i';
//     char *ptr;
//     unsigned long size = 10;
//     ptr = ft_memchr(array, c, size);
//     if (ptr != NULL)
//         printf("Character '%c' is in position %ld\n", *ptr, (ptr - array));
//     else
//         printf("Character not found.\n");
//     return (0);
// }