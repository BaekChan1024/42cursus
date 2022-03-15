/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:50:30 by seubaek           #+#    #+#             */
/*   Updated: 2022/02/13 19:37:11 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	record_time(long long *time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	*time = (long long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	wait_time(t_philo *philo, long long start, long long moment)
{
	long long	cur;

	while (1)
	{
		record_time(&cur);
		if (cur - start >= moment)
			break ;
		if (usleep(10) == -1)
			pthread_mutex_destroy(&philo->info->at_table);
	}
}
