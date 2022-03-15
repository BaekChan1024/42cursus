/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 00:53:56 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 18:07:27 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char		*str;
	int			ret;
	t_args		args;
	va_list		ap;

	str = (char *)format;
	va_start(ap, format);
	if (!str)
		return (0);
	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str = read_args(&args, str, ap);
			ret += check_format(&args, ap);
			continue ;
		}
		ret += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (ret);
}
