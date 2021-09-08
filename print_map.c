/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:27:00 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/08 18:00:37 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	ft_put_image(int i, int j, t_game *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.floor_ptr, \
			j * 32, i * 32);
	if (g->map.map[i][j] == '1')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.wall_ptr, \
				j * 32, i * 32);
	else if (g->map.map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.fire_aux, \
				j * 32 + 5, i * 32 + 5);
	else if (g->map.map[i][j] == 'E')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.flag_aux, \
				j * 32, i * 32 - 20);
	else if (g->map.map[i][j] == 'P')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.bob_aux, \
				j * 32 - 5, i * 32 - 8);
}			

int	ft_print_map(t_game *g)
{
	int		i;
	int		j;
	t_enemy	*aux;

	i = 0;
	aux = g->enemy;
	while (i <= g->map.height - 1)
	{
		j = 0;
		while (j <= g->map.width - 2)
		{
			ft_put_image(i, j, g);
			j++;
		}
		i++;
	}
	while (aux)
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, aux->ice_ptr, \
				aux->y * 32 - 5, aux->x * 32 - 8);
		if (aux->x == g->x && aux->y == g->y)
			ft_exit(g, "Game over");
		aux = aux->next;
	}
	return (1);
}
