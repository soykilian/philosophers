/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:43:45 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/17 15:28:42 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

uint64_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * (uint64_t)1000) + (t.tv_usec / 1000));
}

void	ft_sleep(uint64_t tmsec, t_philo *ph)
{
	uint64_t	act;
	uint64_t	start;

	start = get_time();
	act = start;
	while (act - start < tmsec && ph->table->one_died == 0)
	{
		usleep(100);
		act = get_time();
	}
}

void	reat(t_philo *ph)
{
	pthread_mutex_lock(&ph->table->one_die);
	ph->last = get_time();
	pthread_mutex_unlock(&ph->table->one_die);
	display_info("is eating", ph, get_time());
	ft_sleep(ph->table->tt_eat, ph);
	if (ph->neaten != ph->table->neats)
		ph->neaten += 1;
	pthread_mutex_unlock(&(ph->fork));
	pthread_mutex_unlock(ph->link);
}

void	rtake_forks(t_philo *ph)
{
	if (ph->table->n != 1 && ph->top == 1)
		usleep(100);
	pthread_mutex_lock(&(ph->fork));
	display_info("has taken fork 1", ph, get_time());
	pthread_mutex_lock(ph->link);
	display_info("has taken fork 2", ph, get_time());
}
