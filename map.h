/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:34:22 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/09 15:33:39 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "Libft/libft.h"

/*  MAP   */

/*Map's characters and initial player position*/
typedef struct s_characters
{
	int	space;
	int	wall;
	int	collectible;
	int	exit;
	int	player;
	int	x_p;
	int	y_p;
}				t_charac;

/*Enemy's position, direction and next enemy*/
typedef struct s_enemy
{
	int				x;
	int				y;
	int				dir;
	void			*ice_ptr;
	struct s_enemy	*next;
}				t_enemy;	

typedef struct s_map
{
	int			height;
	int			width;
	char		**map;
	t_charac	charac;
	t_enemy		*enemy;
	int			x;
	int			y;
}				t_map;

/*   GAME   */
# define SPRITE 32
# define ESC_KEY 53
# define U_KEY 126
# define D_KEY 125
# define R_KEY 124
# define L_KEY 123
# define WKEY 13
# define SKEY 1
# define DKEY 2
# define AKEY 0

typedef struct s_img
{
	void	*wall_ptr;
	void	*bob_aux;
	void	*bob_up;
	void	*bob_down;
	void	*bob_right;
	void	*bob_left;
	t_list	*fire;
	t_list	*fire_backup;
	void	*fire_aux;
	void	*floor_ptr;
	t_list	*flag;
	t_list	*flag_backup;
	void	*flag_aux;
	void	*black_ptr;
	void	*ice_bob_r;
	void	*ice_bob_l;
}				t_img;

typedef struct s_game
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_map				map;
	t_img				img;
	t_enemy				*enemy;
	long long unsigned	frames;
	int					x;
	int					y;
	int					moves;
	int					c;
}				t_game;

void	init_t_game(t_game *g, t_map m);
void	init_t_img(t_img *s, t_game g);
void	init_t_map(t_map *m);
void	init_t_charac(t_charac *c);
void	check_map(char *file, t_map *m);
void	read_map(char *file, t_map *m);
void	check_map_characters(t_map *m, t_charac *c);
void	printf_error(char *message, char **str);
void	game_init(t_map m);
t_enemy	*ft_enemynew(int x, int y);
void	ft_enemyadd_back(t_enemy **first, t_enemy *second);
void	ft_reset_enemy(t_game *g);
void	game_init(t_map m);
void	ft_put_image(int i, int j, t_game *g);
int		ft_print_map(t_game *g);
void	animation(t_game *g);
int		ft_key_hook(int keycode, t_game *g);
int		ft_reset(t_game *g);
int		ft_exit(t_game *g, char *message);

#endif
