/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:07:54 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 17:26:04 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthex_ad(t_args *args, unsigned long long num, int padding)
{
	int		ret;

	ret = 0;
	if (num / 16)
		ret += ft_puthex_ad(args, num / 16, padding);
	else if (args->c == 'p')
		ret += write(1, "0x", 2);
	if (args->dot && num == 0 && args->precision >= 0)
	{
		while (padding-- > 0)
			ret += write(1, "0", 1);
		return (ret);
	}
	while (padding-- > 0 && (args->c == 'x' || args->c == 'X'))
		ret += write(1, "0", 1);
	if ((num % 16) >= 10 && (args->c == 'x' || args->c == 'p'))
		ret += ft_putchar((num % 16) - 10 + 'a');
	else if ((num % 16) >= 10 && args->c == 'X')
		ret += ft_putchar((num % 16) - 10 + 'A');
	else
		ret += ft_putchar((num % 16) + '0');
	return (ret);
}

int		min_num_cond(int padding)
{
	int ret;

	ret = 0;
	write(1, "-", 1);
	while (padding-- > 0)
		ret += write(1, "0", 1);
	write(1, "2147483648", 10);
	return (11 + ret);
}

int		is_digit_hex_ad(unsigned long long num)
{
	int digit;

	digit = 0;
	while (num / 16)
	{
		digit++;
		num /= 16;
	}
	digit++;
	return (digit);
}
