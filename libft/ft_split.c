/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:35:43 by mzhukova          #+#    #+#             */
/*   Updated: 2023/11/17 13:47:39 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char sep)
{
	int	counter;
	int	in_word;

	counter = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != sep && in_word == 0)
		{
			in_word = 1;
			counter++;
		}
		if (*s == sep)
			in_word = 0;
		s++;
	}
	return (counter);
}

char	*allocate_word(const char *start, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	**allocate_array(char const *s, char c)
{
	int		words;
	char	**result;

	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**result;

	if (!s)
		return (NULL);
	result = allocate_array(s, c);
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = word_len(s, c);
			result[i++] = allocate_word(s, len);
			s += len;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
