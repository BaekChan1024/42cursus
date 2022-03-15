/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:37:48 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:38:24 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_values(int value[])
{
	int	i;
	int	j;
	int	temp;

	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (value[j] > value[j + 1])
			{
				temp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = temp;
			}
		}
	}
	return (value[2]);
}

int	get_mid_value_five(t_node *node)
{
	int		i;
	int		value[5];
	t_node	*current;

	i = -1;
	current = node;
	while (++i < 5)
	{
		value[i] = current->value;
		if (current->next)
			current = current->next;
		else
			break ;
	}
	return (sort_values(value));
}

int	get_min_value(t_node *node, int size)
{
	int		min;
	t_node	*current;

	min = node->value;
	current = node;
	while (size--)
	{
		if (min > current->value)
			min = current->value;
		if (current->next)
			current = current->next;
		else
			break ;
	}
	return (min);
}

int	get_max_value(t_node *node, int size)
{
	int		max;
	t_node	*current;

	max = node->value;
	current = node;
	while (size--)
	{
		if (max < current->value)
			max = current->value;
		if (current->next)
			current = current->next;
		else
			break ;
	}
	return (max);
}

void	select_pivot(int size, t_deque *deque, t_cmd *cmd)
{
	int	max;
	int	min;

	min = get_min_value(deque->front, size);
	max = get_max_value(deque->front, size);
	cmd->big_pivot = (max + min) / 2;
	cmd->small_pivot = (min + cmd->big_pivot) / 2;
}
