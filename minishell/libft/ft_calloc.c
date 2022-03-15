/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 22:07:39 by bypark            #+#    #+#             */
/*   Updated: 2022/03/02 14:02:12 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = NULL;
	if (!ft_myalloc(ptr, count * size))
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
