/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:26:27 by tbrissia          #+#    #+#             */
/*   Updated: 2022/05/23 11:53:40 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_status(t_philo *philo, char *status)
{
	char	*result;

	result = ft_strjoin(ft_itoa(gettime(NULL)), " ");
	result = ft_strjoin(result, ft_itoa(philo->id + 1));
	result = ft_strjoin(result, " ");
	result = ft_strjoin(result, status);
	result = ft_strjoin(result, "\n");
	write(1, result, ft_strlen(result));
}

size_t	ft_strlen(const char	*str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		counter;
	int		curs;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	result = (char *)malloc((ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (!result)
		return (NULL);
	counter = 0;
	curs = 0;
	while (s1[counter])
		result[curs++] = s1[counter++];
	counter = 0;
	while (s2[counter])
		result[curs++] = s2[counter++];
	result[curs] = '\0';
	return (result);
}

int	ft_atoi(const char *str)
{
	int		nbr;
	int		negative;
	char	*str2;

	nbr = 0;
	negative = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' && negative++ == 0)
		str++;
	else if (*str == '+')
		str++;
	str2 = (char *)str;
	while (*str2 >= '0' && *str2 <= '9')
		str2++;
	if ((str2 - str) > 10 && negative == 0)
		return (-1);
	else if ((str2 - str) > 10 && negative == 1)
		return (0);
	while ((*str >= '0' && *str <= '9'))
		nbr = nbr * 10 + *str++ - 48;
	if (negative != 0)
		nbr -= (nbr * 2);
	return (nbr);
}
