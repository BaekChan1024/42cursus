/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:32:32 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:37:55 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptional_case(t_deque *a, t_deque *b, int size)
{
	if (size <= 3)
	{
		case_three_element(a, b, size, A);
		return (0);
	}
	else if (size == 5)
	{
		case_element_five(a, b, size, A);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_a(t_deque *a, t_deque *b, t_cmd *cmd)
{
	if (a->front->value > cmd->big_pivot)
	{
		rotate(a, A);
		cmd->ra++;
		cmd->rra++;
	}
	else
	{
		push(a, b, B);
		cmd->pb++;
		if (b->front->value > cmd->small_pivot)
		{
			rotate(b, B);
			cmd->rb++;
			cmd->rrb++;
		}
	}
}

static void	reverse_rotate_deque(t_deque *a, t_deque *b, t_cmd *cmd)
{
	int	all_reverse;
	int	remainder;

	if (cmd->rra > cmd->rrb)
	{
		all_reverse = cmd->rrb;
		remainder = cmd->rra - all_reverse;
		while (all_reverse--)
			all_reverse_rotate(a, b, BOTH);
		while (remainder--)
			reverse_rotate(a, A);
	}
	else
	{
		all_reverse = cmd->rra;
		remainder = cmd->rrb - all_reverse;
		while (all_reverse--)
			all_reverse_rotate(a, b, BOTH);
		while (remainder--)
			reverse_rotate(b, B);
	}
}

void	a_to_b(t_deque *a, t_deque *b, int size, int *recursion)
{
	int		roop;
	t_cmd	cmd;

	if (!exceptional_case(a, b, size))
		return ;
	init_cmd(&cmd);
	select_pivot(size, a, &cmd);
	roop = size;
	while (size--)
		push_rotate_a(a, b, &cmd);
	if (*recursion)
		reverse_rotate_deque(a, b, &cmd);
	else
		while (cmd.rrb--)
			reverse_rotate(b, B);
	a_to_b(a, b, cmd.ra, recursion);
	b_to_a(a, b, cmd.rb, recursion);
	b_to_a(a, b, cmd.pb - cmd.rb, recursion);
}
