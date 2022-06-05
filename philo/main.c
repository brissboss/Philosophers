/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:13:17 by tbrissia          #+#    #+#             */
/*   Updated: 2022/05/24 13:20:38 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo			philosophe[250];
	t_time			time;
	int				i;
	int				nb_philo;

	nb_philo = ft_atoi(argv[1]);
	if (protect(argc, argv, nb_philo))
		return (0);
	i = -1;
	while (++i < nb_philo)
	{
		init_philo(argv, &philosophe[i], i);
		arg_sup(&philosophe[i], argv, argc);
		fork_attribution(&philosophe[i], nb_philo, i);
		pthread_create(&philosophe[i].pnj, NULL, philo, &philosophe[i]);
	}
	time.philo = philosophe;
	time.nb_philo = nb_philo;
	pthread_create(&time.thread_time, NULL, time_check, &time);
	close_thread(nb_philo, philosophe);
	pthread_join(time.thread_time, NULL);
	return (0);
}
