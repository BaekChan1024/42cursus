/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:13:20 by bypark            #+#    #+#             */
/*   Updated: 2021/07/12 15:53:22 by byungwook        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	if (!s1)
		return (0);
	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}
