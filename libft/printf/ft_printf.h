/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:58:02 by mzhukova          #+#    #+#             */
/*   Updated: 2024/01/17 16:39:56 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft.h"

int		to_char(char c);
int		to_string(const char *s, va_list *args);
int		to_s(char *str);
int		to_int(int input);
int		to_hex(unsigned long long input);
int		ft_printf(const char *s, ...);
int		input_len(int input);
int		to_hexuplow(int c, char typ);
int		to_undecim(int c);
char	*convert_num(unsigned int n);

#endif