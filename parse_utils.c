/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:55:35 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/16 19:58:58 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

uint64_t	ft_atoicheck(char *nptr)
{
	uint64_t		res;
	int				i;

	res = 0;
	i = 0;
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	if (i != ft_strlen(nptr))
		return (-1);
	return (res);
}

void	ft_fillprog(uint64_t *params, int n, t_prog *p)
{
	p->n = n;
	p->tt_die = params[0];
	p->tt_eat = params[1];
	p->tt_sleep = params[2];
	p->one_died = 0;
	p->have_eaten = 0;
	pthread_mutex_init(&(p->one_die), NULL);
	pthread_mutex_init(&(p->text), NULL);
	p->start = get_time();
	p->neats = -1;
}

int	parse_params(char **argv, t_prog *p, int argc)
{
	int			i;
	uint64_t	*params;
	int			n;

	i = 2;
	params = ft_calloc(argc - 1, sizeof(uint64_t));
	if ((int)ft_atoicheck(argv[1]) != -1)
		n = (int)ft_atoicheck(argv[1]);
	else
		return (0);
	while (argv[i])
	{
		if ((int)ft_atoicheck(argv[i]) != -1)
			params[i - 2] = ft_atoicheck(argv[i]);
		else
			return (0);
		i++;
	}
	ft_fillprog(params, n, p);
	if (argv[5])
		p->neats = (int)ft_atoicheck(argv[5]);
	free(params);
	return (1);
}
