/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 01:22:42 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 15:50:56 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_putstr(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		i += ft_putchar(*s);
		s++;
	}
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_digit(int num)
{
	int digit;

	digit = 0;
	while (num / 10)
	{
		digit++;
		num /= 10;
	}
	digit++;
	return (digit);
}
