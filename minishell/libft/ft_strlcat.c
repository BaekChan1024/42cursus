/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:13:19 by bypark            #+#    #+#             */
/*   Updated: 2021/07/12 15:50:48 by byungwook        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	index;
	char	*s;

	s = (char *)src;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= size)
		return (len_src + size);
	if (size == 0)
		return (len_src);
	index = 0;
	while (s[index] != '\0' && index < (size - 1 - len_dest))
	{
		dest[len_dest + index] = s[index];
		index++;
	}
	dest[len_dest + index] = '\0';
	return (len_dest + len_src);
}
