/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:10:02 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:19:58 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_min_a(t_deque *deque, int max)
{
	if (deque->size == 3)
	{
		if (deque->front->next->value == max)
		{
			reverse_rotate(deque, A);
			swap(deque, A);
		}
	}
	else
	{
		if (deque->front->next->value == max)
		{
			rotate(deque, A);
			swap(deque, A);
			reverse_rotate(deque, A);
		}
	}
}

static void	middle_min_a(t_deque *deque, int max)
{
	if (deque->size == 3)
	{
		if (deque->rear->value == max)
			swap(deque, A);
		else
			rotate(deque, A);
	}
	else
	{
		swap(deque, A);
		if (deque->front->next->value == max)
		{
			rotate(deque, A);
			swap(deque, A);
			reverse_rotate(deque, A);
		}
	}
}

static void	bottom_min_a(t_deque *deque, int max)
{
	if (deque->size == 3)
	{
		if (deque->front->value == max)
			swap(deque, A);
		reverse_rotate(deque, A);
	}
	else
	{
		if (deque->front->value == max)
			swap(deque, A);
		rotate(deque, A);
		swap(deque, A);
		reverse_rotate(deque, A);
		swap(deque, A);
	}
}

void	case_element_three_a(t_deque *deque, int size)
{
	int	min;
	int	max;

	min = get_min_value(deque->front, size);
	max = get_max_value(deque->front, size);
	if (deque->front->value == min)
		top_min_a(deque, max);
	else if (deque->front->next->value == min)
		middle_min_a(deque, max);
	else if (deque->front->next->next->value == min)
		bottom_min_a(deque, max);
}
