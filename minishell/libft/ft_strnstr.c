/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:24:35 by bypark            #+#    #+#             */
/*   Updated: 2021/05/09 16:58:31 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s;
	char	*n;

	s = (char *)str;
	n = (char *)needle;
	if (!*needle)
		return (s);
	i = 0;
	while (i < len && s[i])
	{
		j = 0;
		if (s[i] == n[j])
		{
			while (n[j] == s[i + j] && i + j < len)
			{
				if (n[j + 1] == '\0')
					return (&s[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
