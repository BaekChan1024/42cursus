/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:35:05 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/07 00:34:17 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*str;
	void				*ret;

	ret = dest;
	if (!dest && !src)
		return (0);
	temp = dest;
	str = src;
	if (src < dest)
	{
		str = str + n;
		temp = temp + n;
		while (n--)
			*(--temp) = *(--str);
	}
	else
		while (n--)
			*(temp++) = *(str++);
	return (ret);
}
