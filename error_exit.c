/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:54:35 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/08 18:09:03 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	printf_error(char *message, char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str[i]);
	if (str)
		free(str);
	printf("Error\n%s\n", message);
	exit(0);
}

int	ft_exit(t_game *g, char	*message)
{
	int	i;

	i = g->map.height;
	while (i > 0)
	{
		free(g->map.map[i]);
		i--;
	}
	free(g->map.map[i]);
	free(g->map.map);
	printf("%s\n", message);
	exit(0);
	return (0);
}
