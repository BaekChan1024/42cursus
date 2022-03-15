/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:14:13 by bypark            #+#    #+#             */
/*   Updated: 2021/05/11 10:25:20 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	if (dstsize == 0)
		return (ft_strlen(src));
	index = 0;
	while (*(src + index) && index + 1 < dstsize)
	{
		*(dst + index) = *(src + index);
		index++;
	}
	*(dst + index) = '\0';
	while (*(src + index))
		index++;
	return (ft_strlen(src));
}
