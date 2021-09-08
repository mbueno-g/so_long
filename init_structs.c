/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:40:59 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/08 18:02:50 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	init_t_charac(t_charac *c)
{
	c->space = 0;
	c->wall = 0;
	c->collectible = 0;
	c->exit = 0;
	c->player = 0;
	c->x_p = -1;
	c->y_p = -1;
}

/* Initialize t_map with default values */
void	init_t_map(t_map *m)
{
	m->width = 0;
	m->height = 0;
	m->map = NULL;
}

void	init_t_game(t_game *g, t_map m)
{
	g->mlx_ptr = mlx_init();
	g->map = m;
	g->x = m.charac.x_p;
	g->y = m.charac.y_p;
	g->moves = 0;
	g->c = m.charac.collectible;
	g->win_ptr = mlx_new_window(g->mlx_ptr, \
			(m.width - 1) * SPRITE, (m.height + 1) * SPRITE, ":)");
	g->frames = 0;
}

void	init_t_img_next(t_img *s, t_game g)
{
	s->flag = NULL;
	s->flag_backup = NULL;
	ft_lstadd_back(&s->flag, ft_lstnew(mlx_xpm_file_to_image(g.mlx_ptr, \
				   	"sprites/flag.xpm", &g.map.width, &g.map.height)));
	ft_lstadd_back(&s->flag, ft_lstnew(mlx_xpm_file_to_image(g.mlx_ptr, \
					"sprites/flag2.xpm", &g.map.width, &g.map.height)));
	ft_lstadd_back(&s->flag, ft_lstnew(mlx_xpm_file_to_image(g.mlx_ptr, \
					"sprites/flag3.xpm", &g.map.width, &g.map.height)));
	ft_lstadd_back(&s->flag, ft_lstnew(mlx_xpm_file_to_image(g.mlx_ptr, \
					"sprites/flag4.xpm", &g.map.width, &g.map.height)));
	ft_lstadd_back(&s->flag, ft_lstnew(mlx_xpm_file_to_image(g.mlx_ptr, \
					"sprites/flag5.xpm", &g.map.width, &g.map.height)));
	ft_lstadd_back(&s->flag, ft_lstnew(mlx_xpm_file_to_image(g.mlx_ptr, \
					"sprites/flag6.xpm", &g.map.width, &g.map.height)));
	s->flag_backup = s->flag;
	s->black_ptr = mlx_xpm_file_to_image(g.mlx_ptr, "sprites/black.xpm", \
			&g.map.width, &g.map.height);
	s->ice_bob_r = mlx_xpm_file_to_image(g.mlx_ptr, \
			"sprites/ice_bob_right.xpm", &g.map.width, &g.map.height);
	s->ice_bob_l = mlx_xpm_file_to_image(g.mlx_ptr, "sprites/ice_bob_left.xpm", \
			&g.map.width, &g.map.height);
}

void	init_t_img(t_img *s, t_game g)
{
	s->bob_up = mlx_xpm_file_to_image(g.mlx_ptr, "sprites/bob_up2.xpm", \
			&g.map.width, &g.map.height);
	s->bob_down = mlx_xpm_file_to_image(g.mlx_ptr, "sprites/bob_down2.xpm", \
		   	&g.map.width, &g.map.height);
	s->bob_right = mlx_xpm_file_to_image(g.mlx_ptr, "sprites/bob_right2.xpm", \
		   	&g.map.width, &g.map.height);
	s->bob_aux = s->bob_right;
	s->bob_left = mlx_xpm_file_to_image(g.mlx_ptr, "sprites/bob_left2.xpm", \
			&g.map.width, &g.map.height);
	s->wall_ptr = mlx_xpm_file_to_image(g.mlx_ptr, "sprites/wall.xpm", \
		   	&g.map.width, &g.map.height);
	s->fire = NULL;
	s->fire_backup = NULL;
	ft_lstadd_back(&s->fire, ft_lstnew(mlx_xpm_file_to_image(g.mlx_ptr, \
					"sprites/fire3.xpm", &g.map.width, &g.map.height)));
	ft_lstadd_back(&s->fire, ft_lstnew(mlx_xpm_file_to_image(g.mlx_ptr, \
					"sprites/fire4.xpm", &g.map.width, &g.map.height)));
	s->fire_backup = s->fire;
	s->floor_ptr = mlx_xpm_file_to_image(g.mlx_ptr, "sprites/floor.xpm", \
		   	&g.map.width, &g.map.height);
	init_t_img_next(s, g);
}
