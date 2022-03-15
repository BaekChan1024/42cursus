/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:27:20 by seubaek           #+#    #+#             */
/*   Updated: 2022/02/13 19:30:52 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	exception_case(int valid, t_info *info)
{
	int	i;

	if (info)
	{
		i = 0;
		if (info->fork)
		{
			while (i < info->num_philo)
			{
				pthread_mutex_destroy(&info->fork[i]);
				i++;
			}
		}
		pthread_mutex_destroy(&info->at_table);
		pthread_mutex_destroy(&info->print);
	}
	if (valid == INVALID)
		return (INVALID);
	return (VALID);
}

static bool	init_info(int argc, char **argv, t_info *info)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (false);
	if (!ft_atoi(argv[1], &(info->num_philo))
		|| !ft_atoi(argv[2], &(info->time_die))
		|| !ft_atoi(argv[3], &(info->time_eat))
		|| !ft_atoi(argv[4], &(info->time_sleep))
		|| (argc == 6 && !ft_atoi(argv[5], &(info->num_eat))))
		return (false);
	info->fork = malloc(info->num_philo * sizeof(t_mu));
	info->full_eat = 0;
	if (info->fork == NULL)
		return (false);
	i = 0;
	while (i < info->num_philo)
		if (pthread_mutex_init(&info->fork[i++], NULL))
			return (false);
	if (pthread_mutex_init(&info->at_table, NULL))
		return (false);
	if (pthread_mutex_init(&info->print, NULL))
		return (false);
	return (true);
}

static bool	start_routine(t_info *info, t_philo *philos)
{
	int	i;

	if (pthread_mutex_lock(&info->at_table))
		return (false);
	record_time(&info->start_point);
	i = 0;
	while (i < info->num_philo)
	{
		philos[i].who_am_i = i;
		philos[i].left = i;
		philos[i].right = (i + 1) % info->num_philo;
		philos[i].info = info;
		philos[i].cnt_eat = 0;
		if (pthread_create(&philos[i].action, NULL, action, &philos[i])
			|| pthread_detach(philos[i].action))
			return (false);
		if (pthread_create(&philos[i].monitor, NULL, monitor, &philos[i])
			|| pthread_detach(philos[i].monitor))
			return (false);
		i++;
	}
	usleep(100);
	if (pthread_mutex_lock(&info->at_table))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;

	if (!init_info(argc, argv, &info))
		return (exception_case(INVALID, &info));
	philos = malloc(info.num_philo * sizeof(t_philo));
	if (philos == NULL)
		return (exception_case(INVALID, &info));
	if (start_routine(&info, philos) == false)
		return (exception_case(INVALID, &info));
	return (exception_case(VALID, &info));
}
