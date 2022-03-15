/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:36:15 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/24 20:54:20 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char			**error(char **strs)
{
	unsigned int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

static void			split_str(char **str, size_t *str_len, char c)
{
	size_t i;

	*str += *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

static size_t		count_strs(char const *s, char c)
{
	size_t i;
	size_t count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static size_t		ft_strlcpy(char *dest, const char *src, size_t n)
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

char				**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	size_t	str_len;
	size_t	strs_len;
	size_t	i;

	if (!s)
		return (0);
	strs_len = count_strs(s, c);
	if (!(strs = (char **)malloc(sizeof(char *) * (strs_len + 1))))
		return (0);
	i = 0;
	str = (char *)s;
	str_len = 0;
	while (i < strs_len)
	{
		split_str(&str, &str_len, c);
		if (!(strs[i] = (char *)malloc(sizeof(char) * (str_len + 1))))
			return (error(strs));
		ft_strlcpy(strs[i], str, str_len + 1);
		i++;
	}
	strs[i] = 0;
	return (strs);
}
