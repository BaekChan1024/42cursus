/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:26:04 by bypark            #+#    #+#             */
/*   Updated: 2021/05/09 11:39:27 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	unsigned int	index;

	if (!dst && !src)
		return (NULL);
	index = 0;
	while (num--)
	{
		*((unsigned char *)dst + index) = *((unsigned char *)src + index);
		index++;
	}
	return (dst);
}
