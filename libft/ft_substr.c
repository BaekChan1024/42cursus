/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:44:18 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/10 17:41:06 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size < start)
		len = 0;
	if (size <= len)
		len = size;
	if ((temp = (char *)malloc(sizeof(char) * len + 1)) == 0)
		return (0);
	ft_strlcpy(temp, s + start, len + 1);
	return (temp);
}
