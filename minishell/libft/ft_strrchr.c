/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:55:50 by bypark            #+#    #+#             */
/*   Updated: 2021/05/09 11:49:17 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*ptr;

	ptr = (char *)s;
	index = ft_strlen(s);
	while (ptr[index] != (unsigned char)c)
	{
		index--;
		if (index < 0)
			return (NULL);
	}
	return (&ptr[index]);
}
