/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:29:49 by mikgarci          #+#    #+#             */
/*   Updated: 2022/01/21 20:53:40 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>

typedef struct s_info
{
	int				*id;
	size_t			ph;
	long			timestart;
	long			timedie;
	size_t			timetoeat;
	size_t			timetosleep;
	size_t			timeincrease;
	size_t			eattimes;
	size_t			totph;
	sem_t			*forks;	
	sem_t			*print;
	sem_t			*die;
	sem_t			*start;
}	t_info;

int		set_data(t_info *x, char **argv, int argc);
void	ft_init_data(t_info *x);
void	ft_free_info(t_info *x);
size_t	ft_checktime(long ref);
void	ft_print(char *str, t_info *z);
void	ft_isdead(t_info *z);
void	ft_eat(t_info *z);
void	ft_sleep(t_info *z);
int		ft_onephilo(t_info x);

#endif
