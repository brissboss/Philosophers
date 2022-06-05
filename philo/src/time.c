/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:06:49 by tbrissia          #+#    #+#             */
/*   Updated: 2022/05/24 13:24:23 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	quit_philo(t_time *time)
{
	int	i;

	i = 0;
	while (i < time->nb_philo)
	{
		time->philo[i].quit = -1;
		i++;
	}
}

int	check_time_to_die(t_time *time, int *stop)
{
	long long int	dif_time;
	int				i;

	i = 0;
	while (i < time->nb_philo)
	{
		dif_time = gettime(NULL) - time->philo[i].actual_time;
		if (dif_time > (time->philo[i].time_to_die / 1000))
		{
			printf("%lld %d dead\n", gettime(NULL), (time->philo[i].id + 1));
			quit_philo(time);
			return (-1);
		}
		if (time->philo[i].time_to_stop == 0)
		{
			*stop += 1;
			time->philo[i].time_to_stop = -1;
		}
		i++;
		usleep((i + 1) * 10);
	}
	return (0);
}

void	*time_check(void *p)
{
	t_time				*time;
	int					stop;

	time = (t_time *)p;
	stop = 0;
	while (1)
	{
		if (check_time_to_die(time, &stop))
			return (0);
		if (stop == (time->nb_philo))
		{
			printf("All philosophers eats\n");
			quit_philo(time);
			return (0);
		}
	}
	return (0);
}

long long int	gettime(void *p)
{
	struct timeval	tv;
	long long int	mil;

	(void)p;
	gettimeofday(&tv, NULL);
	mil = tv.tv_sec * 1000;
	mil += tv.tv_usec / 1000;
	return (mil);
}
