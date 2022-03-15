/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:49:10 by bypark            #+#    #+#             */
/*   Updated: 2021/07/25 16:46:28 by byungwook        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *ds, char const *sc, int st, int lt)
{
	int	index;

	index = 0;
	while (st + index < lt)
	{
		ds[index] = sc[st + index];
		index++;
	}
	ds[index] = '\0';
}

static size_t	ft_count_str(const char *s, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		if (s[index] && s[index] != c)
		{
			count++;
			while (s[index] && s[index] != c)
				index++;
		}
		else if (s[index] == c)
			index++;
	}
	return (count);
}

static void	ft_free_all(char **str, int index)
{
	while (index >= 0)
	{
		free(str[index]);
		index--;
	}
	free(str);
}

static void	ft_allocate(char const *s, char c, char **str)
{
	int		index;
	int		str_index;
	int		mark;

	index = 0;
	str_index = 0;
	while (s[index])
	{
		if (s[index] && s[index] != c)
		{
			mark = index;
			while (s[index] && s[index] != c)
				index++;
			if (!ft_myalloc(str[str_index], index - mark + 1))
			{
				ft_free_all(str, str_index - 1);
				return ;
			}
			ft_strcpy(str[str_index], s, mark, index);
			str_index++;
		}
		else if (s[index] == c)
			index++;
	}
}

char	**ft_split2(char const *s, char c)
{
	char		**str;
	size_t		num_count;

	if (!s)
		return (NULL);
	num_count = ft_count_str(s, c);
	str = NULL;
	if (!ft_myalloc(str, sizeof(char *) * (num_count + 1)))
		return (NULL);
	str[num_count] = 0;
	if (num_count == 0)
		return (str);
	ft_allocate(s, c, str);
	return (str);
}
