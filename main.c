/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:51:05 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/08 17:44:53 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "map.h"

/* Check possible file errors */
void	check_file(int argc, char **argv)
{
	int		len;
	char	*suff;

	if (argc == 1)
		printf_error("not enough arguments\n", NULL);
	len = ft_strlen(argv[1]);
	if (argc > 2)
		printf("Only the first map is valid");
	suff = ft_substr(argv[1], len - 4, len);
	if (ft_strncmp(suff, ".ber", ft_strlen(suff)))
	{
		free(suff);
		printf_error("map is not a .ber file\n", NULL);
	}
	free(suff);
}

/* Check possible map errors */
void	check_map(char *file, t_map *m)
{
	t_charac	c;
	int			j;

	read_map(file, m);
	j = 0;
	while (j < m->height - 1)
	{
		if ((ft_strlen(m->map[j + 1]) != ft_strlen(m->map[j]) && \
			ft_strchr(m->map[j + 1], '\n')) || (ft_strlen(m->map[j + 1]) != \
			ft_strlen(m->map[j]) - 1 && !ft_strchr(m->map[j + 1], '\n')))
			printf_error("the map is not a rectangle", m->map);
		j++;
	}
	m->width = ft_strlen(m->map[j - 1]);
	if (m->height < 3 && m->width < 3)
		printf_error("Map needs to be bigger than 3x3", m->map);
	check_map_characters(m, &c);
	m->charac = c;
}

/*Init structs and the hook functions*/
void	game_init(t_map m)
{
	t_game	g;
	t_img	s;

	init_t_game(&g, m);
	init_t_img(&s, g);
	g.enemy = m.enemy;
	g.img = s;
	mlx_loop_hook(g.mlx_ptr, ft_reset, (void *)&g);
	mlx_hook(g.win_ptr, 17, 0, ft_exit, (void *)&g);
	mlx_key_hook(g.win_ptr, ft_key_hook, (void *)&g);
	mlx_loop(g.mlx_ptr);
}

/* Initial function*/
int	main(int argc, char **argv)
{
	t_map	m;

	init_t_map(&m);
	check_file(argc, argv);
	check_map(argv[1], &m);
	game_init(m);
	return (1);
}
