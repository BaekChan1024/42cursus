/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:32:43 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/07 22:41:10 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *start;

	start = (char *)s;
	while (*s)
		s++;
	while (s != start && *s != (char)c)
		--s;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
