/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:18:01 by seubaek           #+#    #+#             */
/*   Updated: 2022/02/13 19:32:37 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*action(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	record_time(&philo->check_point);
	if (philo->who_am_i % 2)
		wait_time(philo, philo->check_point, 100);
	while (1)
	{
		take_fork(philo);
		eat_p(philo);
		put_fork(philo);
		sleep_p(philo);
		think_p(philo);
	}
}

void	*monitor(void *param)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)param;
	record_time(&time);
	wait_time(philo, time, philo->info->time_die - 10);
	while (1)
	{
		record_time(&time);
		if (time - philo->check_point >= (long long)philo->info->time_die
			&& philo->info->time_die != 0)
		{
			print_status(DEAD, philo);
			pthread_mutex_unlock(&philo->info->at_table);
		}
	}
}
