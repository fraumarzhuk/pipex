/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:45:46 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:43:45 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != ch)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

// int main()
// {
//     const char *str = "A noisy noise annoys an oyster most.";
//     int target = 'y';
//     char *result = ft_strchr(str, target);
//     if (result != NULL)
//         printf("'%c' is found at position: %ld\n", target, result - str);
//     else
//         printf("'%c' was not found in the string.\n", target);
//     return 0;
// }
// //