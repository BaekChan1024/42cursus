/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 02:10:30 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/09 19:09:47 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_args(t_args *args, char *str, va_list ap)
{
	if (!str || *str != '%')
		return (str);
	str++;
	init_args(args);
	str = read_flag1(args, str, ap);
	str = read_flag2(args, str);
	str = read_flag3(args, str, ap);
	if (ft_strchr(FORMAT, *str))
	{
		args->c = *str;
		str++;
		return (str);
	}
	return (str);
}
