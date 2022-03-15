/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:25:34 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/10 10:59:14 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_num(int n)
{
	int count;

	count = (n < 0) ? 1 : 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char		put_num(int n)
{
	char c;

	if (n < 0)
		n *= -1;
	c = n + '0';
	return (c);
}

char			*ft_itoa(int n)
{
	int		sign;
	char	*s;
	int		num;

	sign = (n < 0) ? -1 : 1;
	num = count_num(n);
	if (!(s = (char *)malloc(sizeof(char) * num + 1)))
		return (0);
	s[num--] = 0;
	while (num > -1)
	{
		s[num] = put_num(n % 10);
		n /= 10;
		num--;
	}
	if (sign < 0)
		s[0] = '-';
	return (s);
}
