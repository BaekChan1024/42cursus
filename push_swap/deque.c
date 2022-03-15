/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:45:15 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 21:35:11 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*init_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (!deque)
		return (NULL);
	deque->size = 0;
	deque->front = NULL;
	deque->rear = NULL;
	return (deque);
}

static t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	make_list(t_node **temp, t_node **node, t_deque **deque)
{
	if (!*node)
	{
		*node = *temp;
		(*deque)->front = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
}

static int	set_node(char *argv, t_node **node, t_deque **deque)
{
	int		i;
	char	**input_value;
	t_node	*temp;

	input_value = ft_split(argv, ' ');
	if (!input_value || !*input_value)
		return (0);
	i = 0;
	while (input_value[i])
	{
		temp = init_node();
		if (!temp)
			print_error();
		temp->value = ft_atoi(input_value[i]);
		make_list(&temp, node, deque);
		(*deque)->size++;
		free(input_value[i++]);
	}
	free(input_value);
	return (1);
}

void	make_deque(int argc, char **argv, t_deque **deque)
{
	int		i;
	int		ret;
	t_node	*node;

	i = 1;
	node = NULL;
	while (i < argc)
	{
		ret = set_node(argv[i++], &node, deque);
		if (!ret)
			print_error();
	}
	if (!node->next)
		(*deque)->rear = node;
}
