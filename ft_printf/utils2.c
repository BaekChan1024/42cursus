/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 01:24:56 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 15:35:04 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_number(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		is_space(char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int		ft_putlstr(char *str, int len)
{
	int ret;
	int i;

	if (!str)
		return (0);
	ret = 0;
	i = 0;
	while (str[i] && i < len)
	{
		ret += ft_putchar(str[i]);
		i++;
	}
	return (ret);
}

int		ft_putnbr(t_args *args, int num, int padding)
{
	int		ret;

	ret = 0;
	if (args->dot && num == 0 && args->precision >= 0)
	{
		while (padding-- > 0)
			ret += write(1, "0", 1);
		return (ret);
	}
	if (num == -2147483648)
		return (min_num_cond(padding));
	if (num < 0)
	{
		ret += write(1, "-", 1);
		num *= -1;
		padding--;
	}
	while (padding-- > 0)
		ret += write(1, "0", 1);
	if (num / 10)
		ret += ft_putnbr(args, num / 10, padding);
	ret += ft_putchar(num % 10 + '0');
	return (ret);
}

int		ft_unsigned_putnbr(t_args *args, unsigned int num, int padding)
{
	int		ret;

	ret = 0;
	if (args->dot && num == 0 && args->precision >= 0)
	{
		while (padding-- > 0)
			ret += write(1, "0", 1);
		return (ret);
	}
	while (padding-- > 0)
		ret += write(1, "0", 1);
	if (num / 10)
		ret += ft_unsigned_putnbr(args, num / 10, padding);
	ret += ft_putchar(num % 10 + '0');
	return (ret);
}
