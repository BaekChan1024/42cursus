/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:41:07 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 21:46:12 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_deque(t_deque *deque)
{
	t_node	*current;
	t_node	*temp;

	current = deque->front;
	while (current)
	{
		if (current->next)
			temp = current->next;
		else
			temp = NULL;
		free(current);
		if (temp)
			current = temp;
		else
			break ;
	}
	free(deque);
}

int	already_sorted(t_deque *a)
{
	t_node	*current;

	current = a->front;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		if (current->next)
			current = current->next;
		else
			break ;
	}
	return (1);
}

int	push_swap(t_deque *a, t_deque *b)
{
	int	recursion;

	recursion = 0;
	if (already_sorted(a))
	{
		free_deque(a);
		free_deque(b);
		return (1);
	}
	a_to_b(a, b, a->size, &recursion);
	return (0);
}

int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;

	if (argc > 1)
	{
		a = init_deque();
		make_deque(argc, argv, &a);
		b = init_deque();
		if (is_duplicate(a->front))
			print_error();
		if (push_swap(a, b))
			return (0);
		free_deque(a);
		free_deque(b);
	}
	return (0);
}
