/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_under_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:03:38 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:04:09 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_size_two(t_deque *a, t_deque *b, int flag)
{
	if (flag == A)
	{
		if (a->front->value > a->front->next->value)
			swap(a, A);
	}
	else
	{
		if (b->front->value < b->front->next->value)
			swap(b, B);
		push(b, a, A);
		push(b, a, A);
	}
}

void	case_three_element(t_deque *a, t_deque *b, int size, int flag)
{
	if (size == 3)
	{
		if (flag == A)
			case_element_three_a(a, size);
		else
			case_element_three_b(a, b, size);
	}
	else if (size == 2)
		case_size_two(a, b, flag);
	else if (size == 1)
		if (flag == B)
			push(b, a, A);
}
