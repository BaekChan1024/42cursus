/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:44:14 by seubaek           #+#    #+#             */
/*   Updated: 2021/09/24 11:17:12 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	if (!*haystack || len == 0)
		return (0);
	j = 0;
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && j + i < len)
		{
			i++;
			if (!needle[i])
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (0);
}

void	ft_exit(char *msg)
{
	int	len;

	write(1, "Error\n", 6);
	len = ft_strlen(msg);
	write(1, msg, len);
	write(1, "\n", 1);
	exit(0);
}

int	get_digit(int num)
{
	int	digit;

	digit = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		digit++;
		num *= -1;
	}
	while (num)
	{
		digit++;
		num /= 10;
	}
	return (digit);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		digit;

	digit = get_digit(num);
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	str[digit] = 0;
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[--digit] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
