/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:05:19 by bypark            #+#    #+#             */
/*   Updated: 2021/07/12 15:56:32 by byungwook        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	index;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = NULL;
	if (!ft_myalloc(str, sizeof(char) * len + 1))
		return (NULL);
	index = 0;
	while (index < len)
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
