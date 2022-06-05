/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:08:52 by theo              #+#    #+#             */
/*   Updated: 2022/05/24 13:25:50 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_philo(char **argv, t_philo *philo, int i)
{
	philo->id = i;
	philo->quit = 0;
	philo->time_to_die = (ft_atoi(argv[2]) * 1000);
	philo->time_to_eat = (ft_atoi(argv[3]) * 1000);
	philo->time_to_sleep = (ft_atoi(argv[4]) * 1000);
}

int	protect(int argc, char **argv, int nb_philo)
{
	int	i;

	i = -1;
	if (!(argc > 4 && argc < 7))
	{
		printf("Not enough argument\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
	{
		printf("There is no philosopher...\n");
		return (1);
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) == 0)
		{
			while (++i < nb_philo)
				printf("%lld %d is thinking\n", gettime(NULL), i + 1);
			printf("Philosophers must not eat\n");
			return (1);
		}
	}
	return (0);
}

void	arg_sup(t_philo *philo, char **argv, int argc)
{
	if (argc == 5)
		philo->time_to_stop = 2147483647;
	else
		philo->time_to_stop = ft_atoi(argv[5]);
}

void	fork_attribution(t_philo *philo, int nb_philo, int i)
{
	pthread_mutex_t	fork[250];

	if (philo->id == (nb_philo - 1))
	{
		philo->left_fork = &fork[i];
		philo->right_fork = &fork[0];
	}
	else
	{
		philo->left_fork = &fork[i];
		philo->right_fork = &fork[i + 1];
	}
	pthread_mutex_init(&fork[i], NULL);
}

void	close_thread(int nb_philo, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_join(philo[i].pnj, NULL);
		pthread_mutex_destroy(philo[i].left_fork);
		i++;
	}
}
