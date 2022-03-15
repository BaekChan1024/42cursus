/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:49:49 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/10 18:15:38 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t ret;

	ret = 0;
	while (*dest && ret < n)
	{
		ret++;
		dest++;
	}
	while (*src && (ret + 1) < n)
	{
		*dest = *src;
		dest++;
		src++;
		ret++;
	}
	if (ret < n)
		*dest = 0;
	while (*src)
	{
		ret++;
		src++;
	}
	return (ret);
}
