/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:05:21 by bypark            #+#    #+#             */
/*   Updated: 2021/07/12 15:57:44 by byungwook        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	front;
	size_t	back;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	back = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (back > front && s1[back - 1] && ft_strchr(set, s1[back - 1]))
		back--;
	str = NULL;
	if (!ft_myalloc(str, sizeof(char) * (back - front + 1)))
		return (NULL);
	if (str)
		ft_strlcpy(str, &((char *)s1)[front], back - front + 1);
	return (str);
}
