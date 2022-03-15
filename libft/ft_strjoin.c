/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:43:45 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/10 17:23:01 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned int	size;
	char			*temp;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1);
	size += ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * size + 1);
	if (!p)
		return (0);
	p[size] = 0;
	temp = p;
	while (*s1)
		*(temp++) = *(s1++);
	while (*s2)
		*(temp++) = *(s2++);
	return (p);
}
