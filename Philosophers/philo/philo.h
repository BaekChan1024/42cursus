/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:28:05 by seubaek           #+#    #+#             */
/*   Updated: 2022/02/13 19:34:14 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>

# define VALID 0
# define INVALID 1

typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mu;

typedef enum e_status
{
	TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	COMPLETE
}				t_status;

typedef struct s_info
{
	int			num_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			num_eat;
	int			full_eat;
	t_mu		*fork;
	t_mu		at_table;
	t_mu		print;
	long long	start_point;
}				t_info;

typedef struct s_philo
{
	int			who_am_i;
	int			left;
	int			right;
	int			cnt_eat;
	t_info		*info;
	t_th		action;
	t_th		monitor;
	long long	check_point;
}				t_philo;

bool			ft_atoi(const char *nptr, int *out);
void			record_time(long long *time);
void			wait_time(t_philo *philo, long long start, long long moment);
bool			print_status(t_status status, t_philo *philo);
void			*monitor(void *param);
void			*action(void *param);
void			take_fork(t_philo *philo);
void			put_fork(t_philo *philo);
void			eat_p(t_philo *philo);
void			sleep_p(t_philo *philo);
void			think_p(t_philo *philo);

#endif