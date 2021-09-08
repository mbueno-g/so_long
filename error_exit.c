/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:54:35 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/07 20:13:41 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	printf_error(char *message, char **str)
{
    int    i;

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

int    ft_exit(t_game *g)
{
    int    i;

    i = g->map.height;
    //AÑADIR NUEVOS PUNTEROS
    mlx_destroy_image(g->mlx_ptr, g->img.floor_ptr);
    mlx_destroy_image(g->mlx_ptr, g->img.black_ptr);
    //mlx_destroy_image(g->mlx_ptr, g->img.fire_ptr);
    //mlx_destroy_image(g->mlx_ptr, g->img.exit_ptr);
    mlx_destroy_image(g->mlx_ptr, g->img.wall_ptr);
    mlx_clear_window(g->mlx_ptr, g->win_ptr);
    mlx_destroy_window(g->mlx_ptr, g->win_ptr);
    //mlx_destroy_display(g->mlx_ptr);
    //free(g->mlx_ptr);
    while (i > 0)
    {
        free(g->map.map[i]);
        i--;
    }
    free(g->map.map[i]);
    free(g->map.map);
    //system("leaks a.out");
    exit(0);
    return (0);
}
