/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:38:39 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/10 13:22:42 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*str;

	if (!dest && !src)
		return (0);
	temp = dest;
	str = src;
	while (n--)
	{
		*(temp++) = *(str++);
	}
	return (dest);
}
