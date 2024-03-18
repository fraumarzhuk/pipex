/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:30:43 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:45:30 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strrchr(set, s1[start]))
		start++;
	while (end > start && ft_strrchr(set, s1[end - 1]))
		end--;
	res = malloc((end - start + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (start < end)
	{
		res[i++] = s1[start++];
	}
	res[i] = '\0';
	return (res);
}

// int main (void)
// {
// 	char *s1 = "ABC_ABC";
// 	char *set = "ABC";
// 	char *r = ft_strtrim(s1, set);
// 	printf("Result: %s\n", r);
// 	return (0);
// }