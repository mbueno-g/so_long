/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:50:56 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/08 17:42:00 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "Libft/libft.h"
#include <mlx.h>

void	ft_direction(char dir, t_game *g)
{
	if (dir == 'U')
	{
		g->x = g->x - 1;
		g->img.bob_aux = g->img.bob_up;
	}
	if (dir == 'D')
	{
		g->x = g->x + 1;
		g->img.bob_aux = g->img.bob_down;
	}
	if (dir == 'R')
	{
		g->y = g->y + 1;
		g->img.bob_aux = g->img.bob_right;
	}
	if (dir == 'L')
	{
		g->y = g->y - 1;
		g->img.bob_aux = g->img.bob_left;
	}
}

void	ft_go(char dir, t_game *g)
{
	int		x;
	int		y;

	x = g->x;
	y = g->y;
	ft_memset(&g->map.map[g->x][g->y], '0', g->map.map[g->x][g->y] != 'E');
	ft_direction(dir, g);
	if (g->map.map[g->x][g->y] == 'C')
		g->c--;
	if (ft_strchr("C0", g->map.map[g->x][g->y]) || \
			(g->c == 0 && 'E' == g->map.map[g->x][g->y]))
		g->moves++;
	if ((g->c != 0 && g->map.map[g->x][g->y] == 'E') || \
			g->map.map[g->x][g->y] == '1')
	{
		g->x = x;
		g->y = y;
	}
	ft_memset(&g->map.map[g->x][g->y], 'P', g->map.map[g->x][g->y] != 'E');
	if ((g->c == 0 && g->map.map[g->x][g->y] == 'E'))
		ft_exit(g, "Congratulations!!");
}

int	ft_key_hook(int keycode, t_game *g)
{
	if (keycode == ESC_KEY)
		ft_exit(g, "Pressed exit");
	else if (keycode == U_KEY || keycode == WKEY)
		ft_go('U', g);
	else if (keycode == D_KEY || keycode == SKEY)
		ft_go('D', g);
	else if (keycode == R_KEY || keycode == DKEY)
		ft_go('R', g);
	else if (keycode == L_KEY || keycode == AKEY)
		ft_go('L', g);
	return (0);
}

/* Moves enemies */
void	ft_reset_enemy(t_game *g)
{
	t_enemy	*aux;

	aux = g->enemy;
	while (aux)
	{
		if (g->map.map[aux->x][aux->y] == 'G')
			ft_memset(&g->map.map[aux->x][aux->y], '0', 1);
		if (ft_strchr("0P", g->map.map[aux->x][aux->y + aux->dir]))
		{
			if (aux->ice_ptr == NULL)
				aux->ice_ptr = g->img.ice_bob_r;
			aux->y += aux->dir;
		}
		else
		{
			if (aux->ice_ptr == g->img.ice_bob_l)
				aux->ice_ptr = g->img.ice_bob_r;
			else
				aux->ice_ptr = g->img.ice_bob_l;
			aux->dir = aux->dir * (-1);
		}
		aux = aux->next;
	}
}

/* Function hooks to the loop; called every frame */
/* Updates flag's ptr and enemies every X frames,
 * prints the updated map and the score*/
int	ft_reset(t_game *g)
{
	char	*move;
	int		i;

	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	g->frames++;
	animation(g);
	if (g->frames % 12 == 0 || g->frames == 1)
		ft_reset_enemy(g);
	ft_print_map(g);
	i = 0;
	while (i < g->map.width)
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.black_ptr, \
				i * 32, g->map.height * 32);
		i++;
	}
	move = ft_itoa(g->moves);
	mlx_string_put(g->mlx_ptr, g->win_ptr, (g->map.width * 1 / 2) * 32, \
			g->map.height * 32, 0xFFFFFF, move);
	free(move);
	return (0);
}
