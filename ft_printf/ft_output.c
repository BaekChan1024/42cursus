/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 02:32:51 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 18:06:28 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		output_c(t_args *args, char c, int len)
{
	int ret;

	ret = 0;
	if (!args->minus && !args->zero)
		ret = print_width(args->width, len);
	while (args->zero && args->c == '%' && args->width - len > 0)
	{
		ret += write(1, "0", 1);
		args->width--;
	}
	ret += ft_putchar(c);
	if (args->minus)
		ret += print_width(args->width, len);
	return (ret);
}

int		output_s(t_args *args, char *str, int len)
{
	int ret;

	ret = 0;
	if (!args->minus)
		ret = print_width(args->width, len);
	ret += ft_putlstr(str, len);
	if (args->minus)
		ret += print_width(args->width, len);
	return (ret);
}

int		output_d(t_args *args, int num, int len, int padding)
{
	int ret;

	ret = 0;
	if (!args->minus)
		ret += print_width(args->width, len + padding);
	ret += ft_putnbr(args, num, padding);
	if (args->minus)
		ret += print_width(args->width, len + padding);
	return (ret);
}

int		output_u(t_args *args, unsigned int num, int len, int padding)
{
	int ret;

	ret = 0;
	if (!args->minus)
		ret += print_width(args->width, len + padding);
	if (args->c == 'u')
		ret += ft_unsigned_putnbr(args, num, padding);
	else if (args->c == 'x' || args->c == 'X')
		ret += ft_puthex(args, num, padding);
	if (args->minus)
		ret += print_width(args->width, len + padding);
	return (ret);
}

int		output_p(t_args *args, unsigned long long num, int len, int padding)
{
	int ret;

	len = len + 2;
	ret = 0;
	if (!args->minus)
		ret += print_width(args->width, len + padding);
	ret += ft_puthex_ad(args, num, padding);
	if (args->minus)
		ret += print_width(args->width, len + padding);
	return (ret);
}
