/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:54:12 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/10 13:49:26 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		count;

	count = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * count + 1);
	if (!p)
		return (0);
	p[count] = 0;
	while (count--)
		p[count] = s[count];
	return (p);
}
