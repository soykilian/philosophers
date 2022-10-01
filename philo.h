/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:25:05 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/16 20:01:50 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
typedef struct s_prog{
	int						n;
	uint64_t				tt_die;
	uint64_t				tt_eat;
	uint64_t				tt_sleep;
	int						neats;
	int						have_eaten;
	uint64_t				start;
	int						one_died;
	pthread_mutex_t			one_die;
	pthread_mutex_t			text;
}			t_prog;

typedef struct s_philo{
	int					idx;
	t_prog				*table;
	int					neaten;
	uint64_t			last;
	int					top;
	int					eat;
	pthread_mutex_t		fork;
	pthread_mutex_t		*link;
	pthread_t			thread;
	int					state;
}			t_philo;
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_sleep(uint64_t tmsec, t_philo *ph);
void		reat(t_philo *ph);
void		rtake_forks(t_philo *ph);
void		ft_mainthread(void *arg);
int			display_info(char *str, t_philo *ph, uint64_t tim);
uint64_t	get_time(void);
void		handle_threads(t_philo *ph, t_prog p);
void		ft_thread_start(void *arg);
int			parse_params(char **argv, t_prog *p, int argc);
#endif
