/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:54:35 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/09 15:56:48 by mbueno-g         ###   ########.fr       */
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

void	free_struct(t_game *g, t_list *lst)
{
	t_list	*aux;
	
	aux = NULL;
	while (lst)
	{
		aux = lst;
		lst = lst->next;
		mlx_destroy_image(g->mlx_ptr, aux->content);
		free(aux);
	}
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
	mlx_destroy_image(g->mlx_ptr, g->img.bob_up);
	mlx_destroy_image(g->mlx_ptr, g->img.bob_down);
	mlx_destroy_image(g->mlx_ptr, g->img.bob_right);
	mlx_destroy_image(g->mlx_ptr, g->img.bob_left);
	mlx_destroy_image(g->mlx_ptr, g->img.wall_ptr);
	mlx_destroy_image(g->mlx_ptr, g->img.floor_ptr);
	mlx_destroy_image(g->mlx_ptr, g->img.black_ptr);
	mlx_destroy_image(g->mlx_ptr, g->img.ice_bob_r);
	mlx_destroy_image(g->mlx_ptr, g->img.ice_bob_l);
	free_struct(g, g->img.fire_backup);
	free_struct(g, g->img.flag_backup);
	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	printf("%s\n", message);
	exit(0);
	return (0);
}
