/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:33:26 by mikgarci          #+#    #+#             */
/*   Updated: 2022/01/21 20:55:27 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "../inc/philo.h"

static void	ft_run(t_info z)
{
	while (z.isdead[0])
	{
		pthread_mutex_lock (&z.mutex[z.rf]);
		ft_print("has taken a fork", z);
		usleep(50);
		pthread_mutex_lock (&z.mutex[z.lf]);
		ft_print("has taken a fork", z);
		ft_eat(&z);
		pthread_mutex_unlock (&z.mutex[z.lf]);
		pthread_mutex_unlock (&z.mutex[z.rf]);
		ft_sleep(&z);
		if (!z.eattimes)
			break ;
	}
}

void	*function(void	*x)
{
	struct timeval	current_time;
	t_info			z;

	z = *(t_info *) x;
	z.lf = z.ph;
	z.rf = z.ph + 1;
	if (z.ph == z.totph)
		z.rf = 1;
	while (1)
	{
		if (ft_checktime(z.timestart) >= 1000)
			break ;
		usleep(300);
	}
	gettimeofday (&current_time, NULL);
	z.timestart = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	z.timedie = z.timestart + z.timeincrease;
	if (z.ph % 2 == 1)
		usleep(1000);
	ft_run(z);
	return (NULL);
}

static int	ft_onephilo(t_info x)
{
	if (x.totph == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(x.timeincrease * 1000);
		printf("%lu 1 died\n", x.timeincrease);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	x;

	if (!set_data(&x, argv, argc))
		return (1);
	if (ft_onephilo(x))
		return (0);
	ft_init_data(&x);
	x.ph = 1;
	while (x.ph <= x.totph)
	{
		pthread_create(&x.id[x.ph], NULL, function, (void *) &x);
		usleep(100);
		x.ph++;
	}
	x.ph = 1;
	while (x.ph <= x.totph)
	{
		pthread_join(x.id[x.ph], NULL);
		x.ph++;
	}
	ft_free_info(&x);
	return (0);
}
