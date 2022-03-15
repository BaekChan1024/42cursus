/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:42:13 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/24 20:54:16 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static size_t		ft_strlen(const char *s)
{
	size_t ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

char				*ft_strjoin(char const *s1, char const *s2)
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
