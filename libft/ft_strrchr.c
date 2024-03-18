/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:59:29 by mariannazhu       #+#    #+#             */
/*   Updated: 2023/11/18 13:45:00 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// int main()
// {
//     const char *str = "A noisy noise annoys an oyster most.";
//     int trg = 'n';
//     char *result = ft_strrchr(str, trg);
//     if (result != NULL)
//     {
//         printf("Last '%c' is found at position: %ld\n", trg, result - str);
//         printf("Substring: %s\n", result);
//     }
//     else
//     {
//         printf("Character '%c' not found in the string\n", trg);
//     }
//     return (0);
// }