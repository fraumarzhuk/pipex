/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:37:31 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:43:05 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*b;

	b = (unsigned char *) str;
	while (len--)
	{
		*b++ = (unsigned char) c;
	}
	return (str);
}

// int main()
// {
// 	char str[7] = "bonjour";
// 	ft_memset(str, '!' , 4);
// 	printf("Modified string: %s\n", str);
// }