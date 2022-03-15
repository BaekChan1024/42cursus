/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:32:12 by seubaek           #+#    #+#             */
/*   Updated: 2022/02/13 19:36:38 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	inner_print_status(t_status status)
{
	if (status == TAKEN)
		printf(" has taken a fork\n");
	else if (status == EATING)
		printf(" is eating\n");
	else if (status == SLEEPING)
		printf(" is sleeping\n");
	else if (status == THINKING)
		printf(" is thinking\n");
	else if (status == DEAD)
		printf(" died\n");
}

bool	print_status(t_status status, t_philo *philo)
{
	long long	time;

	if (pthread_mutex_lock(&philo->info->print))
		return (false);
	record_time(&time);
	printf("%lld ms ", time - philo->info->start_point);
	if (status == COMPLETE)
		printf("The philosopher simulation is over\n");
	else
	{
		printf("%d", philo->who_am_i + 1);
		inner_print_status(status);
	}
	if (status == DEAD || status == COMPLETE)
		return (false);
	if (pthread_mutex_unlock(&philo->info->print))
		return (false);
	return (true);
}
