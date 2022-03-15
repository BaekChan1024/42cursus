/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:11:37 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:41:58 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(int size)
{
	if (size == 0)
		return (1);
	return (0);
}

int	insert_front(t_deque *deque, int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_deque));
	if (!node)
		return (0);
	node->value = value;
	if (is_empty(deque->size))
	{
		node->prev = NULL;
		node->next = NULL;
		deque->front = node;
		deque->rear = node;
	}
	else
	{
		deque->front->prev = node;
		node->next = deque->front;
		deque->front = node;
		node->prev = NULL;
	}
	deque->size++;
	return (1);
}

int	insert_rear(t_deque *deque, int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = value;
	if (is_empty(deque->size))
	{
		node->prev = NULL;
		node->next = NULL;
		deque->front = node;
		deque->rear = node;
	}
	else
	{
		deque->rear->next = node;
		node->prev = deque->rear;
		deque->rear = node;
		node->next = NULL;
	}
	deque->size++;
	return (1);
}

int	delete_front(t_deque *deque)
{
	t_node	*temp;

	if (is_empty(deque->size))
		return (0);
	if (deque->size == 1)
	{
		temp = deque->front;
		deque->front = NULL;
		deque->rear = NULL;
		free(temp);
	}
	else
	{
		temp = deque->front;
		deque->front = deque->front->next;
		deque->front->prev = NULL;
		free(temp);
	}
	deque->size--;
	return (1);
}

int	delete_rear(t_deque *deque)
{
	t_node	*temp;

	if (is_empty(deque->size))
		return (0);
	if (deque->size == 1)
	{
		temp = deque->rear;
		deque->front = NULL;
		deque->rear = NULL;
		free(temp);
	}
	else
	{
		temp = deque->rear;
		deque->rear = deque->rear->prev;
		deque->rear->next = NULL;
		free(temp);
	}
	deque->size--;
	return (1);
}
