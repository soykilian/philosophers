/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:50:04 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/17 15:27:14 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mainthread(void *arg)
{
	t_philo		*ph;
	int			i;
	int			n;

	i = 0;
	n = 0;
	ph = (t_philo *)arg;
	while (ph->table->one_died != 1)
	{
		pthread_mutex_lock(&ph->table->one_die);
		if (get_time() - ph[i].last > ph->table->tt_die)
		{
			display_info("died", &ph[i], get_time());
			ph->table->one_died = 1;
		}
		if (ph->table->have_eaten == ph->table->n)
			ph->table->one_died = 1;
		pthread_mutex_unlock(&ph->table->one_die);
		usleep(100);
		i++;
		if (i == ph->table->n)
			i = 0;
	}
}

void	ft_thread_start(void *arg)
{
	t_philo	*act;

	act = (t_philo *) arg;
	while (act->table->one_died != 1 && act->table->neats != act->neaten)
	{
		rtake_forks(act);
		reat(act);
		if (act->table->one_died != 1)
		{
			display_info("is sleeping", act, get_time());
			ft_sleep(act->table->tt_sleep, act);
		}
		if (act->table->one_died != 1)
			display_info("thinking", act, get_time());
		pthread_mutex_lock(&act->table->one_die);
		if (act->table->neats == act->neaten)
			act->table->have_eaten += 1;
		pthread_mutex_unlock(&act->table->one_die);
		usleep(100);
	}
}

int	display_info(char *str, t_philo *ph, uint64_t tim)
{
	uint64_t	t;

	pthread_mutex_lock(&ph->table->text);
	t = tim - ph->table->start;
	if (ph->table->one_died == 0 && ph->neaten != ph->table->neats)
		printf("[%llu] [%i] %s\n", t, ph->idx, str);
	pthread_mutex_unlock(&ph->table->text);
	return (1);
}

void	handle_threads(t_philo *ph, t_prog p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (p.n % 2 == 0)
		i = p.n / 2;
	else
		i = (p.n - 1) / 2;
	if (p.n < 2)
		i = 0;
	while (i > 0)
	{
		ph[j].top = 1;
		j += 2;
		i--;
	}
}
