/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:31:38 by mikgarci          #+#    #+#             */
/*   Updated: 2022/01/21 20:55:28 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>

void	ft_init_data(t_info *x)
{
	struct timeval	current_time;
	size_t			i;

	gettimeofday (&current_time, NULL);
	x->timestart = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	x->timestart = x->timestart + 1000;
	x->id = malloc((x->totph + 1) * sizeof(pthread_t));
	x->isdead = malloc(sizeof(int));
	x->isdead[0] = 1;
	x->mutex = malloc((x->totph + 1) * sizeof(pthread_mutex_t));
	i = 0;
	while (i < x->totph + 1)
	{
		pthread_mutex_init(&x->mutex[i], NULL);
		i++;
	}
	x->printmutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&x->printmutex[0], NULL);
}

void	ft_free_info(t_info *x)
{
	size_t	i;

	free(x->id);
	free(x->isdead);
	i = 0;
	while (i < x->totph + 1)
	{
		pthread_mutex_destroy(&x->mutex[i]);
		i++;
	}
	free(x->mutex);
	pthread_mutex_destroy(&x->printmutex[0]);
	free(x->printmutex);
}
