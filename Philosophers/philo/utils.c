/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:41:57 by seubaek           #+#    #+#             */
/*   Updated: 2022/02/13 19:37:26 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_number(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

bool	ft_atoi(const char *nptr, int *out)
{
	int	sign;
	int	ret;

	sign = 1;
	ret = 0;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while (*nptr)
	{
		if (!is_number(*nptr))
			return (false);
		ret *= 10;
		ret += *(nptr++) - '0';
	}
	*out = ret * sign;
	return (true);
}
