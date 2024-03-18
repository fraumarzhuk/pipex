/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:33:16 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:44:50 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nl;

	nl = ft_strlen(needle);
	if (!nl)
		return ((char *) haystack);
	while (*haystack && len >= nl)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, nl))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

// int main() {
//     const char *big = "A noisy noise annoys an oyster most.";
//     const char *smol = "noise annoys an oyster";
//     size_t len = 30;
//     char *result = ft_strnstr(big, smol, len);
//     if (result != NULL) {
//         printf("Substring found at position: %ld\n", result - big);
//         printf("Substring: %s\n", result);
//     } else {
//         printf("Substring not found\n");
//     }
//     return (0);
// }