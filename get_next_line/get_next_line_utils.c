/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:34:53 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/15 18:32:47 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		s1_size;
	int		s2_size;

	if (!(s1) && !(s2))
		return (NULL);
	if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!(p = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1))))
		return (NULL);
	ft_strlcpy(p, s1, s1_size + 1);
	free(s1);
	ft_strlcat(p + (s1_size), s2, s2_size + 1);
	return (p);
}

size_t		ft_strlen(const char *s)
{
	size_t ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		count;

	count = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * count + 1);
	if (!p)
		return (0);
	p[count] = 0;
	while (count--)
		p[count] = s[count];
	return (p);
}

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t ret;

	ret = 0;
	while (*dest && ret < n)
	{
		ret++;
		dest++;
	}
	while (*src && (ret + 1) < n)
	{
		*dest = *src;
		dest++;
		src++;
		ret++;
	}
	if (ret < n)
		*dest = 0;
	while (*src)
	{
		ret++;
		src++;
	}
	return (ret);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t ret;

	if (!dest && !src)
		return (0);
	ret = 0;
	while (src[ret] && ret + 1 < n)
	{
		dest[ret] = src[ret];
		ret++;
	}
	if (n != 0)
		dest[ret] = 0;
	while (src[ret])
		ret++;
	return (ret);
}
