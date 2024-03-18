/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:57:09 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/18 13:41:06 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len);

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
	{
		ft_memset(s, 0, n);
	}
}

// int main()
// {
//     char str[10] = "bonjour";
//     printf("Before: %s\n", str);
//     ft_bzero(str, strlen(str));
//     printf("After:  %s\n", str);
//     return (0);
// }