/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:41:37 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/08 17:46:52 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	animation(t_game *g)
{
	g->img.flag_aux = g->img.flag->content;
	g->img.fire_aux = g->img.fire->content;
	if (g->frames % 8 == 0)
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
}
