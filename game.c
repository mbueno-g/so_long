/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:50:56 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/07 20:13:24 by mbueno-g         ###   ########.fr       */
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
	if (ft_strchr("C0", g->map.map[g->x][g->y]) || (g->c == 0 && 'E' == g->map.map[g->x][g->y]))
		g->moves++;
	if ((g->c != 0 && g->map.map[g->x][g->y] == 'E') || g->map.map[g->x][g->y] == '1')
	{
		g->x = x;
		g->y = y;
	}
	ft_memset(&g->map.map[g->x][g->y], 'P', g->map.map[g->x][g->y] != 'E');
	if ((g->c == 0 && g->map.map[g->x][g->y] == 'E'))
	{
		//mlx_clear_window(g->mlx_ptr, g->win_ptr);
		//mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.over_ptr, 1 * 32, 1 * 32);
		ft_exit(g);
	}
}

int	ft_key_hook(int keycode, t_game *g)
{
	if (keycode == ESC_KEY)
		ft_exit(g);
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

void	ft_put_image(int i, int j, t_game *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.floor_ptr, j * 32, i * 32);
	if (g->map.map[i][j] == '1')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.wall_ptr, j * 32, i * 32);
	else if (g->map.map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.fire_aux, j * 32 + 5, i * 32 + 5);
	else if (g->map.map[i][j] == 'E')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.flag_aux, j * 32, i * 32 - 20);
	else if (g->map.map[i][j] == 'P')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.bob_aux, j * 32 - 5, i * 32 - 8);
}			

int	ft_print_map(t_game *g)
{
	int	i;
	int	j;
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
	while(aux)
	{
		if (g->map.map[aux->x][aux->y] == 'G')
			ft_memset(&g->map.map[aux->x][aux->y], '0', 1);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.ice_bob_ptr, aux->y * 32 - 5, aux->x * 32 - 8);
		if (aux->x == g->x && aux->y == g->y)
			ft_exit(g);
		aux = aux->next;
	}
	return (1);
}

void	ft_reset_enemy(t_game *g)
{
	t_enemy	*aux;

	aux = g->enemy;
	while (aux)
	{
		if (ft_strchr("0P", g->map.map[aux->x][aux->y + aux->dir]))
			aux->y += aux->dir;
		else
			aux->dir = aux->dir * (-1);
		aux = aux->next;
	}
	
}

int	ft_reset(t_game *g)
{
	char	*move;
	int		i;

	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	//reset fames a 0
	/*Animations */
	g->frames++;
	g->img.flag_aux = g->img.flag->content;
	g->img.fire_aux = g->img.fire->content;
	if (g->frames % 10 == 0)
	{
		g->img.fire = g->img.fire->next;
		if (g->img.fire)
			g->img.fire_aux = g->img.fire->content;
		else
			g->img.fire = g->img.fire_backup;
		g->img.flag = g->img.flag->next;
		if (g->img.flag)	
			g->img.flag_aux = g->img.flag->content;
		else
			g->img.flag = g->img.flag_backup;
	}
	/*Update ice bob omb */
	if (g->frames % 12 == 0)
		ft_reset_enemy(g);

	/*Draw the whole map */
	ft_print_map(g);

	/*Draw the score */
	i = 0;
	while (i < g->map.width)
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.black_ptr, i * 32, g->map.height * 32);
		i++;
	}
	move = ft_itoa(g->moves);
	mlx_string_put(g->mlx_ptr, g->win_ptr, (g->map.width * 1 / 2) * 32, g->map.height * 32, 0xFFFFFF, move);
	free(move);
	return (0);
}
