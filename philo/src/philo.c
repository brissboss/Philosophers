/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:00:35 by tbrissia          #+#    #+#             */
/*   Updated: 2022/05/23 13:09:54 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	eat(t_philo *philo)
{
	if ((philo->id % 2) == 1)
		usleep((philo->id + 1) * 10);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	if (philo->quit != -1)
		print_status(philo, "has taken a fork");
	if (philo->quit != -1)
		print_status(philo, "is eating");
	philo->actual_time = gettime(NULL);
	usleep(philo->time_to_eat);
	philo->time_to_stop--;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	dodo(t_philo *philo)
{
	if (philo->quit != -1)
		print_status(philo, "is sleeping");
	usleep(philo->time_to_sleep);
}

void	*philo(void	*p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	philo->actual_time = gettime(NULL);
	while (42)
	{
		if (philo->quit != -1)
			print_status(philo, "is thinking");
		if (philo->right_fork == philo->left_fork)
			return (0);
		eat(philo);
		if (philo->time_to_stop < 1 || philo->quit == -1)
			return (0);
		dodo(philo);
		if (philo->quit == -1)
			return (0);
	}
	return (0);
}
