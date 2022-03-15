/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:39:49 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 19:22:28 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	init_cmd(t_cmd *cmd)
{
	cmd->ra = 0;
	cmd->rb = 0;
	cmd->pa = 0;
	cmd->pb = 0;
	cmd->rra = 0;
	cmd->rrb = 0;
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *arg)
{
	int		i;
	int		sign;
	long	value;

	if (!check_arg(arg))
		print_error();
	i = 0;
	sign = 1;
	value = 0;
	if (arg[i] == '-' || arg[i] == '+')
		if (arg[i++] == '-')
			sign *= -1;
	while (arg[i])
		value = value * 10 + (arg[i++] - '0');
	value = sign * value;
	if (value > INT_MAX || value < INT_MIN)
		print_error();
	return (value);
}

int	is_duplicate(t_node *node)
{
	t_node	*current;
	t_node	*check;

	current = node;
	while (current != NULL)
	{
		check = current->next;
		while (check != NULL)
		{
			if (current->value == check->value)
				return (1);
			else
				check = check->next;
		}
		current = current->next;
	}
	return (0);
}
