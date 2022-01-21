/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:29:49 by mikgarci          #+#    #+#             */
/*   Updated: 2022/01/10 20:30:17 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_info
{
	pthread_t		*id;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*printmutex;
	size_t			ph;
	int				*isdead;
	long			timestart;
	long			timedie;
	size_t			timetoeat;
	size_t			timetosleep;
	size_t			timeincrease;
	size_t			lf;
	size_t			rf;
	size_t			eattimes;
	size_t			totph;
}	t_info;

int		set_data(t_info *x, char **argv, int argc);
void	ft_init_data(t_info *x);
void	ft_free_info(t_info *x);
size_t	ft_checktime(long ref);
void	ft_print(char *str, t_info z);
void	ft_isdead(t_info *z);
void	ft_eat(t_info *z);
void	ft_sleep(t_info *z);

#endif
