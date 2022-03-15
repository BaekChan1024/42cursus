/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 03:46:46 by seubaek           #+#    #+#             */
/*   Updated: 2021/05/10 14:02:59 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *pre;
	t_list *next;

	pre = *lst;
	while (pre != NULL)
	{
		next = pre->next;
		ft_lstdelone(pre, del);
		pre = next;
	}
	*lst = NULL;
}
