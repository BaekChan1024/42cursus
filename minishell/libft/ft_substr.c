/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:05:06 by bypark            #+#    #+#             */
/*   Updated: 2021/07/12 15:58:36 by byungwook        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sptr;
	size_t	index;

	index = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sptr = (char *)malloc((len + 1) * sizeof(char));
	if (!sptr)
		return (0);
	sptr[len] = 0;
	while (index < len)
		*(sptr + index++) = *(s + start++);
	return (sptr);
}
