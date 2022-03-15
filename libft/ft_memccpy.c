/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:49:14 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/07 21:58:06 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*str;
	unsigned char		find;
	int					i;

	temp = dest;
	str = src;
	find = c;
	i = 1;
	while (n--)
	{
		*(temp) = *(str);
		if (*str == find)
			return (dest + i);
		i++;
		temp++;
		str++;
	}
	return (0);
}
