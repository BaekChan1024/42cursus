/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:47:50 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:34:52 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_deque *from, t_deque *to, int flag)
{
	int	value;

	value = from->front->value;
	insert_front(to, value);
	delete_front(from);
	if (flag == A)
		write(1, "pa\n", 3);
	else if (flag == B)
		write(1, "pb\n", 3);
}

void	swap(t_deque *deque, int flag)
{
	int	value1;
	int	value2;

	value1 = deque->front->value;
	delete_front(deque);
	value2 = deque->front->value;
	delete_front(deque);
	insert_front(deque, value1);
	insert_front(deque, value2);
	if (flag == A)
		write(1, "sa\n", 3);
	else if (flag == B)
		write(1, "sb\n", 3);
}

void	rotate(t_deque *deque, int flag)
{
	int	value;

	value = deque->front->value;
	delete_front(deque);
	insert_rear(deque, value);
	if (flag == A)
		write(1, "ra\n", 3);
	else if (flag == B)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_deque *deque, int flag)
{
	int	value;

	value = deque->rear->value;
	delete_rear(deque);
	insert_front(deque, value);
	if (flag == A)
		write(1, "rra\n", 4);
	else if (flag == B)
		write(1, "rrb\n", 4);
}
