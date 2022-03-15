/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:48:34 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/10 15:59:19 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char*)haystack);
	if (!*haystack || len == 0)
		return (0);
	j = 0;
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && j + i < len)
		{
			i++;
			if (!needle[i])
				return ((char*)&haystack[j]);
		}
		j++;
	}
	return (0);
}
