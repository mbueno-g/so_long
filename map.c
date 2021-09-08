/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:51:57 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/08 17:01:24 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "map.h"

void	ft_create_map(int fd, t_map *m, char *line)
{
	int	i;

	m->map = malloc(sizeof(char *) * (m->height + 1));
	if (!m->map)
		printf_error("Malloc failed", NULL);
	i = 0;
	while (1)
	{
		m->map[i] = NULL;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		m->map[i] = ft_substr(line, 0, ft_strlen(line));
		free(line);
		i++;
	}
	close(fd);
	m->map[i] = NULL;
}

void	read_map(char *file, t_map *m)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf_error("Missing file", NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		m->height++;
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf_error("Missing file", NULL);
	if (m->height == 0)
		printf_error("Empty file", NULL);
	ft_create_map(fd, m, NULL);
}

void	check_characters(int i, int j, t_map *m, t_charac *c)
{
	if (!ft_strchr("01CEPG\n", m->map[i][j]))
		printf_error("impossible character", m->map);
	if (m->map[i][j] == '0')
		c->space++;
	else if (m->map[i][j] == '1')
		c->wall++;
	if (m->map[0][j] != '1' || m->map[m->height - 1][j] != '1')
		printf_error("Not surrounded by wall", m->map);
	if (m->map[i][0] != '1' || m->map[i][m->width - 2] != '1')
		printf_error("Not surrounded by wall", m->map);
	if (m->map[i][j] == 'C')
		c->collectible++;
	else if (m->map[i][j] == 'E')
		c->exit++;
	else if (m->map[i][j] == 'P')
		c->player++;
	else if (m->map[i][j] == 'G')
		ft_enemyadd_back(&m->enemy, ft_enemynew(i, j));
	if (m->map[i][j] == 'P' && c->player == 1)
	{
		c->x_p = i;
		c->y_p = j;
	}
}

void	check_map_characters(t_map *m, t_charac *c)
{
	int		i;
	int		j;

	m->enemy = NULL;
	i = 0;
	init_t_charac(c);
	while (i <= m->height - 1)
	{
		j = 0;
		while (j <= m->width - 2)
		{
			check_characters(i, j, m, c);
			j++;
		}
		i++;
	}
	if (c->player == 0 || c->player > 1)
		printf_error("incorrect number of players", m->map);
	else if (c->collectible == 0)
		printf_error("incorrect number of collectibles", m->map);
	else if (c->exit == 0 || c->exit > 1)
		printf_error("incorrect number of exits", m->map);
}
