/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cond.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 00:57:25 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 17:21:02 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_args(t_args *args)
{
	args->c = 0;
	args->has_precision = 0;
	args->has_width = 0;
	args->width = 0;
	args->precision = 0;
	args->minus = 0;
	args->prec_star = 0;
	args->wid_star = 0;
	args->zero = 0;
	args->dot = 0;
}

char	*read_flag1(t_args *args, char *s, va_list ap)
{
	while (*s == '-' || *s == '0')
	{
		if (*s == '-')
			args->minus = 1;
		if (*s == '0')
			args->zero = 1;
		s++;
	}
	if (*s == '*')
	{
		args->wid_star = 1;
		args->has_width = 1;
		args->width = va_arg(ap, int);
		if (args->width < 0)
		{
			args->minus = 1;
			args->width *= -1;
		}
		s++;
	}
	if (args->minus && args->zero)
		args->zero = 0;
	return (s);
}

char	*read_flag2(t_args *args, char *s)
{
	if (is_number(*s) && !args->wid_star)
	{
		args->has_width = 1;
		args->width = ft_atoi(s);
		s += is_digit(args->width);
	}
	if (*s == '.')
	{
		args->dot = 1;
		s++;
	}
	if (is_number(*s) && !args->prec_star)
	{
		args->has_precision = 1;
		while (*s == '0' && is_number(*(s + 1)))
			s++;
		args->precision = ft_atoi(s);
		if (args->precision < 0)
			args->minus = 1;
		s += is_digit(args->precision);
	}
	return (s);
}

char	*read_flag3(t_args *args, char *s, va_list ap)
{
	if (!args->has_precision && *s == '*')
	{
		args->prec_star = 1;
		args->has_precision = 1;
		args->precision = va_arg(ap, int);
		s++;
	}
	if (args->dot && args->zero && args->precision >= 0)
		args->zero = 0;
	return (s);
}

int		check_format(t_args *args, va_list ap)
{
	if (args->c == '%')
		return (cond_c(args, ap));
	else if (args->c == 'c')
		return (cond_c(args, ap));
	else if (args->c == 's')
		return (cond_s(args, ap));
	else if (args->c == 'd' || args->c == 'i')
		return (cond_d(args, ap));
	else if (args->c == 'u')
		return (cond_u(args, ap));
	else if (args->c == 'x' || args->c == 'X')
		return (cond_x(args, ap));
	else if (args->c == 'p')
		return (cond_p(args, ap));
	return (0);
}
