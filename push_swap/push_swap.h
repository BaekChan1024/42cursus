/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:29:56 by seungchanba       #+#    #+#             */
/*   Updated: 2021/08/01 21:50:36 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define A 1
# define B 2
# define BOTH 3

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_deque
{
	int				size;
	struct s_node	*front;
	struct s_node	*rear;
}				t_deque;

typedef struct s_cmd
{
	int	big_pivot;
	int	small_pivot;
	int	ra;
	int	rb;
	int	pa;
	int	pb;
	int	rra;
	int	rrb;
}				t_cmd;

size_t			ft_strlcpy(char *dest, const char *src, size_t n);
char			**ft_split(char *s, char c);
void			init_cmd(t_cmd *cmd);
void			print_error(void);
int				ft_isdigit(int c);
int				ft_atoi(char *arg);
int				check_arg(char *arg);
int				is_duplicate(t_node *node);
void			make_deque(int argc, char **argv, t_deque **deque);
t_deque			*init_deque(void);
int				is_empty(int size);
int				insert_front(t_deque *deque, int value);
int				insert_rear(t_deque *deque, int value);
int				delete_front(t_deque *deque);
int				delete_rear(t_deque *deque);
void			push(t_deque *from, t_deque *to, int flag);
void			swap(t_deque *deque, int flag);
void			rotate(t_deque *deque, int flag);
void			reverse_rotate(t_deque *deque, int flag);
void			all_rotate(t_deque *a, t_deque *b, int flag);
void			all_reverse_rotate(t_deque *a, t_deque *b, int flag);
void			all_swap(t_deque *a, t_deque *b, int flag);
int				get_mid_value_five(t_node *node);
int				get_min_value(t_node *node, int size);
int				get_max_value(t_node *node, int size);
void			select_pivot(int size, t_deque *deque, t_cmd *cmd);
void			case_element_three_a(t_deque *deque, int size);
void			case_element_three_b(t_deque *a, t_deque *b, int size);
void			case_three_element(t_deque *a, t_deque *b, int size, int flag);
void			case_size_two(t_deque *a, t_deque *b, int flag);
void			case_element_five(t_deque *a, t_deque *b, int size, int flag);
void			a_to_b(t_deque *a, t_deque *b, int size, int *recursion);
void			b_to_a(t_deque *a, t_deque *b, int size, int *recursion);
int				push_swap(t_deque *a, t_deque *b);
int				already_sorted(t_deque *a);
void			free_deque(t_deque *deque);

#endif
