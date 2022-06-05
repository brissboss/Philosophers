/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:40:29 by theo              #+#    #+#             */
/*   Updated: 2022/05/20 17:31:46 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static long long int	compt_int(long long int n)
{
	long long int	compt;

	compt = 0;
	while (n > 9)
	{
		n = n / 10;
		compt++;
	}
	return (compt);
}

static void	ft_save_my_life(long long int *n, long long int *compt_bool)
{
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			*n += 1;
			compt_bool[1] = 1;
		}
		*n *= -1;
		compt_bool[0] = compt_bool[0] + 1;
		compt_bool[2] = 1;
	}
}

char	*ft_itoa(long long int n)
{
	char			*nbr;
	long long int	compt_bool[3];
	long long int	duo;

	compt_bool[0] = 1;
	compt_bool[1] = 0;
	compt_bool[2] = 0;
	ft_save_my_life(&n, compt_bool);
	duo = n;
	compt_bool[0] += compt_int(duo);
	nbr = (char *)malloc(sizeof(char) * (compt_bool[0] + 1));
	if (! nbr)
		return (NULL);
	nbr[compt_bool[0]] = '\0';
	compt_bool[0]--;
	while (compt_bool[0] >= 0)
	{
		nbr[compt_bool[0]--] = (n % 10) + 48;
		n = n / 10;
	}
	if (compt_bool[1] == 1)
		nbr[10] = '8';
	if (compt_bool[2] == 1)
		nbr[0] = '-';
	return (nbr);
}
