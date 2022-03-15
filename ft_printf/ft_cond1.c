/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cond1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 02:17:37 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 17:23:27 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cond_c(t_args *args, va_list ap)
{
	int		ret;
	char	c;
	int		len;

	len = 0;
	if (args->c == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	len++;
	ret = output_c(args, c, len);
	return (ret);
}

int		cond_s(t_args *args, va_list ap)
{
	int		ret;
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (args->has_precision && args->precision > 0)
		len = (len > args->precision) ? args->precision : len;
	if (args->dot && args->precision == 0)
		len = 0;
	ret = output_s(args, str, len);
	return (ret);
}

int		cond_d(t_args *args, va_list ap)
{
	int ret;
	int num;
	int padding;
	int len;

	num = va_arg(ap, int);
	len = is_digit(num);
	if (num == 0 && args->dot && args->precision >= 0)
		len = 0;
	if (num < 0)
		padding = ((len - 1) < args->precision) ?\
		args->precision - (len - 1) : 1;
	else
		padding = (len < args->precision) ? args->precision - len : 0;
	if (num == INT_MIN)
		padding = 0;
	if (args->zero && args->precision <= 0)
		padding = args->width - len;
	ret = output_d(args, num, len, padding);
	return (ret);
}

int		cond_u(t_args *args, va_list ap)
{
	int						ret;
	unsigned int			num;
	int						len;
	int						padding;

	ret = 0;
	num = va_arg(ap, unsigned int);
	len = unsigned_is_digit(num);
	if (num == 0 && args->dot && args->precision >= 0)
		len = 0;
	padding = (len < args->precision) ? args->precision - len : 0;
	if (args->zero && args->precision <= 0)
		padding = args->width - len;
	ret = output_u(args, num, len, padding);
	return (ret);
}

int		cond_x(t_args *args, va_list ap)
{
	int						ret;
	unsigned int			num;
	int						hex_len;
	int						padding;

	ret = 0;
	num = va_arg(ap, unsigned int);
	hex_len = is_digit_hex(num);
	if (num == 0 && args->dot && args->precision >= 0)
		hex_len = 0;
	padding = (hex_len < args->precision) ? args->precision - hex_len : 0;
	if (args->zero && args->precision <= 0)
		padding = args->width - hex_len;
	ret = output_u(args, num, hex_len, padding);
	return (ret);
}
