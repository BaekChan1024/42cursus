/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:05:07 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:03:53 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_rotate(t_deque *a, t_deque *b, int flag)
{
	rotate(a, flag);
	rotate(b, flag);
	if (flag == BOTH)
		write(1, "rr\n", 3);
}

void	all_reverse_rotate(t_deque *a, t_deque *b, int flag)
{
	reverse_rotate(a, flag);
	reverse_rotate(b, flag);
	if (flag == BOTH)
		write(1, "rrr\n", 4);
}

void	all_swap(t_deque *a, t_deque *b, int flag)
{
	swap(a, flag);
	swap(b, flag);
	if (flag == BOTH)
		write(1, "ss\n", 3);
}
