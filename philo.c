/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:25:05 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/17 15:36:20 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	ft_links(t_philo *ph, t_prog prog)
{
	int	i;

	i = 0;
	ph[0].link = &(ph[prog.n - 1].fork);
	while (i < prog.n - 1)
	{
		ph[i + 1].link = &(ph[i].fork);
		i++;
	}
	handle_threads(ph, prog);
}

void	ft_endprogram(t_philo *ph)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(ph->table->text));
	pthread_mutex_destroy(&(ph->table->one_die));
	while (i < ph->table->n)
	{
		pthread_mutex_destroy(&(ph->fork));
		i++;
	}
	free(ph);
}

void	ft_threads(t_philo *ph)
{
	int			i;
	pthread_t	ppal;

	i = 0;
	if (ph->table->neats == 0)
		return ;
	while (i < ph->table->n)
	{
		pthread_create(&(ph[i].thread), NULL, (void *)ft_thread_start, &ph[i]);
		i++;
	}
	i = 0;
	pthread_create(&ppal, NULL, (void *)ft_mainthread, ph);
	pthread_join(ppal, NULL);
	if (ph->table->n == 1)
		return ;
	while (i < ph->table->n)
	{
		pthread_join(ph[i].thread, NULL);
		i++;
	}
}

void	ft_init_philo(t_philo *philo, t_prog p, int i)
{
	philo->idx = i + 1;
	philo->table = &p;
	philo->neaten = 0;
	philo->top = 0;
	philo->state = 0;
	philo->last = p.start;
	philo->eat = 0;
	pthread_mutex_init(&philo->fork, NULL);
}

int	main(int argc, char **argv)
{
	t_prog	prog;
	t_philo	*ph;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (write(1, "Wrong number of arguments\n", 26));
	if (!parse_params(argv, &prog, argc))
		return (write(1, "Wrong format for arguments\n", 28));
	ph = (t_philo *)ft_calloc(prog.n, sizeof(t_philo));
	while (i < prog.n)
	{
		ft_init_philo(&ph[i], prog, i);
		i++;
	}
	ft_links(ph, prog);
	ft_threads(ph);
	ft_endprogram(ph);
	return (0);
}
