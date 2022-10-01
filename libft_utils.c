/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:00:55 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/17 15:31:52 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*output;
	size_t	i;

	i = 0;
	output = (char *)malloc(nmemb * size);
	if (!output)
		return (output);
	while (i < (size * nmemb))
	{
		output[i] = 0;
		i++;
	}
	return ((void *)output);
}
