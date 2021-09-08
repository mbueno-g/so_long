#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <mlx.h>
//# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h> //exit
# include "Libft/libft.h"

/*  MAP   */

/*Map's characters and initial player position*/
typedef struct s_characters
{
	int	space; //0
	int	wall; //1
	int	collectible; //C
	int	exit; //E
	int	player; //P
	int	x_p;
	int	y_p;
}				t_charac;

/*Enemy's position, direction and next enemy*/
typedef struct s_enemy
{
	int	x;
	int	y;
	int	dir;
	struct s_enemy *next;
}				t_enemy;	

typedef struct s_map
{
	int		height;
	int		width;
	char		**map;
	t_charac	charac;
	t_enemy		*enemy;
	int		x; //posicion actual del player
	int		y;
}		t_map;

/*Número de caracteres del mapa*/

void	check_map(char *file, t_map *m);
void	read_map(char *file, t_map *m);
void	check_map_characters(t_map *m, t_charac *c);
void	printf_error(char *message, char **str);
void    game_init(t_map m);
/*   GAME   */

# define SPRITE 32

   /* KEYS LINUX (definirlas al compilar como con BUFFER_SIZE*/
/*# define ESC_KEY 65307
# define U_KEY 119 //W
# define R_KEY 100 //D
# define D_KEY 115 //S
# define L_KEY 97 // A*/

#define ESC_KEY 53
#define U_KEY 126
#define D_KEY 125
#define R_KEY 124
#define L_KEY 123
#define WKEY 13
#define SKEY 1
#define DKEY 2
#define AKEY 0


/*  SPRITES  */

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
	void	*ice_bob_ptr;
}				t_img;

/*Inicio del juego*/
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_img	img;
	t_enemy	*enemy;
	long long unsigned frames;
	int	x;
	int	y;
	int moves;
	int	c; //number of collectible
}				t_game;

/*Init structs*/
void    init_t_game(t_game *g, t_map m);
void    init_t_img(t_img *s, t_game g);
void    init_t_map(t_map *m);
void	init_t_charac(t_charac *c);

t_enemy *ft_enemynew(int x, int y);
 void    ft_enemyadd_back(t_enemy **first, t_enemy *second);

void	game_init(t_map m);

int ft_key_hook(int keycode, t_game *g);
int ft_reset(t_game *g);
int    ft_exit(t_game *g);


#endif
