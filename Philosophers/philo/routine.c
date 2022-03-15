/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:31:45 by seubaek           #+#    #+#             */
/*   Updated: 2022/02/13 19:36:50 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->info->fork[philo->left])
		|| print_status(TAKEN, philo) == false)
	{
		pthread_mutex_unlock(&philo->info->at_table);
		return ;
	}
	if (pthread_mutex_lock(&philo->info->fork[philo->right])
		|| print_status(TAKEN, philo) == false)
	{
		pthread_mutex_unlock(&philo->info->at_table);
		return ;
	}
}

void	put_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->info->fork[philo->left])
		|| pthread_mutex_unlock(&philo->info->fork[philo->right]))
		pthread_mutex_unlock(&philo->info->at_table);
}

void	eat_p(t_philo *philo)
{
	record_time(&philo->check_point);
	if (print_status(EATING, philo) == false)
		pthread_mutex_unlock(&philo->info->at_table);
	wait_time(philo, philo->check_point, philo->info->time_eat);
	philo->cnt_eat++;
	if (philo->cnt_eat == philo->info->num_eat)
	{
		philo->info->full_eat++;
		if (philo->info->full_eat >= philo->info->num_philo)
			if (print_status(COMPLETE, philo) == false)
				pthread_mutex_unlock(&philo->info->at_table);
	}
}

void	sleep_p(t_philo *philo)
{
	long long	time;

	record_time(&time);
	if (print_status(SLEEPING, philo) == false)
		pthread_mutex_unlock(&philo->info->at_table);
	wait_time(philo, time, philo->info->time_sleep);
}

void	think_p(t_philo *philo)
{
	if (print_status(THINKING, philo) == false)
		pthread_mutex_unlock(&philo->info->at_table);
}
