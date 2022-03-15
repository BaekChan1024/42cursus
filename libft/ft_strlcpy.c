/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:36:26 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/07 01:11:14 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t ret;

	if (!dest && !src)
		return (0);
	ret = 0;
	while (src[ret] && ret + 1 < n)
	{
		dest[ret] = src[ret];
		ret++;
	}
	if (n != 0)
		dest[ret] = 0;
	while (src[ret])
		ret++;
	return (ret);
}
