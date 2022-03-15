/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 00:28:05 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/10 13:41:54 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_start(const char *s, char const *set, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && ft_strchr(set, s[i]))
		i++;
	return (i);
}

static size_t	is_end(const char *s, char const *set, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && ft_strchr(set, s[len - i - 1]))
		i++;
	return (len - i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*p;
	size_t			start;
	size_t			end;
	size_t			len;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = is_start(s1, set, len);
	end = is_end(s1, set, len);
	if (start >= end)
		return (ft_strdup(""));
	if (!(p = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (0);
	ft_strlcpy(p, s1 + start, end - start + 1);
	return (p);
}
