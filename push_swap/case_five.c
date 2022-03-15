/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:14:12 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:38:44 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a(t_deque *a, t_deque *b, int size)
{
	int	pivot;
	int	push_v;
	int	rotate_v;

	push_v = 0;
	rotate_v = 0;
	pivot = get_mid_value_five(a->front);
	while (size--)
	{
		if (a->front->value < pivot)
		{
			push(a, b, B);
			push_v++;
		}
		else
		{
			rotate(a, A);
			rotate_v++;
		}
		if (push_v == 2)
			break ;
	}
	while (rotate_v--)
		reverse_rotate(a, A);
}

static void	sort_b(t_deque *a, t_deque *b, int size)
{
	int	pivot;
	int	push_v;
	int	rotate_v;

	push_v = 0;
	rotate_v = 0;
	pivot = get_mid_value_five(b->front);
	while (size--)
	{
		if (b->front->value >= pivot)
		{
			push(b, a, A);
			push_v++;
		}
		else
		{
			rotate(b, B);
			rotate_v++;
		}
		if (push_v == 3)
			break ;
	}
	while (rotate_v--)
		reverse_rotate(b, B);
}

void	case_element_five(t_deque *a, t_deque *b, int size, int flag)
{
	if (flag == A)
		sort_a(a, b, size);
	else
		sort_b(a, b, size);
	case_element_three_a(a, 3);
	case_size_two(a, b, B);
}
