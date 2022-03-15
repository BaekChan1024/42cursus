/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cond2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:27:01 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 16:29:34 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cond_p(t_args *args, va_list ap)
{
	int						ret;
	unsigned long long		num;
	int						hex_len;
	int						padding;

	ret = 0;
	num = va_arg(ap, unsigned long long);
	hex_len = is_digit_hex_ad(num);
	if (num == 0 && args->dot && args->precision >= 0)
		hex_len = 0;
	padding = (hex_len < args->precision) ? args->precision - hex_len : 0;
	if (args->zero && args->precision <= 0)
		padding = args->width - hex_len;
	ret = output_p(args, num, hex_len, padding);
	return (ret);
}
