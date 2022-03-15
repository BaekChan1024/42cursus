/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 01:26:58 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 18:04:41 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (is_number(*str))
	{
		if (num < LLONG_MAX - (*str - '0') / 10)
		{
			num *= 10;
			num += *str - '0';
		}
		else
			num = (sign == -1) ? LLONG_MIN : LLONG_MAX;
		str++;
	}
	return (sign * num);
}

int		unsigned_is_digit(unsigned int num)
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

int		ft_puthex(t_args *args, unsigned int num, int padding)
{
	int		ret;

	ret = 0;
	if (args->dot && num == 0 && args->precision >= 0)
	{
		while (padding-- > 0)
			ret += write(1, "0", 1);
		return (ret);
	}
	while (padding-- > 0 && (args->c == 'x' || args->c == 'X'))
		ret += write(1, "0", 1);
	if (num / 16)
		ret += ft_puthex(args, num / 16, padding);
	else if (args->c == 'p')
		ret += write(1, "0x", 2);
	if ((num % 16) >= 10 && (args->c == 'x' || args->c == 'p'))
		ret += ft_putchar((num % 16) - 10 + 'a');
	else if ((num % 16) >= 10 && args->c == 'X')
		ret += ft_putchar((num % 16) - 10 + 'A');
	else
		ret += ft_putchar((num % 16) + '0');
	return (ret);
}

int		is_digit_hex(unsigned int num)
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

int		print_width(int width, int size)
{
	int ret;

	ret = 0;
	while (width - size > 0)
	{
			ret += ft_putchar(' ');
		width--;
	}
	return (ret);
}
