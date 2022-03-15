/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:42:58 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:35:14 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_min_b(t_deque *deque, int max)
{
	if (deque->size == 3)
	{
		rotate(deque, B);
		if (deque->front->next->value == max)
			swap(deque, B);
	}
	else
	{
		swap(deque, B);
		rotate(deque, B);
		swap(deque, B);
		reverse_rotate(deque, B);
		if (deque->front->next->value == max)
			swap(deque, B);
	}
}

static void	middle_min_b(t_deque *deque, int max)
{
	if (deque->size == 3)
	{
		reverse_rotate(deque, B);
		if (deque->front->next->value == max)
			swap(deque, B);
	}
	else
	{
		rotate(deque, B);
		swap(deque, B);
		reverse_rotate(deque, B);
		if (deque->front->next->value == max)
			swap(deque, B);
	}
}

static void	bottom_min_b(t_deque *deque, int max)
{
	if (deque->front->next->value == max)
		swap(deque, B);
}

void	case_element_three_b(t_deque *a, t_deque *b, int size)
{
	int	min;
	int	max;

	min = get_min_value(b->front, size);
	max = get_max_value(b->front, size);
	if (b->front->value == min)
		top_min_b(b, max);
	else if (b->front->next->value == min)
		middle_min_b(b, max);
	else if (b->front->next->next->value == min)
		bottom_min_b(b, max);
	push(b, a, A);
	push(b, a, A);
	push(b, a, A);
}
