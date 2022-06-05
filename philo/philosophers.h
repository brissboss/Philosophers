/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:27:01 by tbrissia          #+#    #+#             */
/*   Updated: 2022/06/05 09:58:30 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

// struct for one philosophers
typedef struct s_philo
{
	pthread_t			pnj;
	int					id;
	int					quit;
	int					time_to_stop;
	long long int		time_to_die;
	long long int		time_to_eat;
	long long int		time_to_sleep;
	long long int		actual_time;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}	t_philo;

// struct for time checker
typedef struct s_time
{
	pthread_t	thread_time;
	t_philo		*philo;
	int			nb_philo;
}	t_time;

// Utils
int				ft_atoi(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
char			*ft_itoa(long long int n);
void			print_status(t_philo *philo, char *status);

// Function init
void			init_philo(char **argv, t_philo *philo, int i);
int				protect(int argc, char **argv, int nb_philo);
void			arg_sup(t_philo *philo, char **argv, int argc);
void			fork_attribution(t_philo *philo, int nb_philo, int i);
void			close_thread(int nb_philo, t_philo *philo);

// Routine philosophers
void			eat(t_philo *philo);
void			dodo(t_philo *philo);
void			*philo(void *p);

// Function for time management
void			*time_check(void *p);
long long int	gettime(void *p);

#endif
