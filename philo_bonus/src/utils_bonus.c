/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:35:50 by mikgarci          #+#    #+#             */
/*   Updated: 2022/01/21 20:53:41 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <semaphore.h>
#include "../inc/philo_bonus.h"

size_t	ft_checktime(long ref)
{
	struct timeval	current_time;
	long			now;

	gettimeofday (&current_time, NULL);
	now = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (now - ref);
}

void	ft_print(char *str, t_info *z)
{
	struct timeval	current_time;
	long			refin;

	gettimeofday (&current_time, NULL);
	refin = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	sem_wait(z->print);
	sem_wait(z->die);
	printf("%ld %zu %s\n", refin - z->timestart, z->ph, str);
	sem_post(z->die);
	sem_post(z->print);
}

void	ft_isdead(t_info *z)
{
	struct timeval	current_time;
	long			refin;

	gettimeofday (&current_time, NULL);
	refin = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	if (refin - z->timedie > 0)
	{
		sem_wait(z->die);
		printf("%ld %zu died\n", refin - z->timestart, z->ph);
		exit(1);
	}
}

void	ft_eat(t_info *z)
{
	long			refin;
	struct timeval	current_time;

	gettimeofday (&current_time, NULL);
	refin = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	ft_print("is eating", z);
	while (1)
	{
		usleep(200);
		ft_isdead(z);
		if (ft_checktime(refin) >= z->timetoeat)
			break ;
	}
	gettimeofday (&current_time, NULL);
	refin = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	z->timedie = refin + z->timeincrease;
	z->eattimes--;
}

void	ft_sleep(t_info *z)
{
	long			refin;
	struct timeval	current_time;

	gettimeofday (&current_time, NULL);
	refin = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	ft_print("is sleeping", z);
	while (1)
	{
		usleep(200);
		if (ft_checktime(refin) >= z->timetosleep)
			break ;
	}
	ft_print("is thinking", z);
}
