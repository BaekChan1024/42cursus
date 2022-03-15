/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:06:03 by bypark            #+#    #+#             */
/*   Updated: 2021/05/06 10:02:45 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *ds, const void *sc, int c, size_t n)
{
	size_t			index;
	int				flag;
	unsigned char	*tmp;

	index = 0;
	flag = 0;
	tmp = (unsigned char *)sc;
	while (!flag && index < n)
	{
		if (tmp[index] == (unsigned char)c)
			flag = 1;
		index++;
	}
	if (flag)
	{
		ft_memcpy(ds, sc, index);
		return (ds + index);
	}
	else
	{
		ft_memcpy(ds, sc, n);
		return (0);
	}
}
