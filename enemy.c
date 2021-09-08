/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:08:29 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/08 17:56:05 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/* Create a new enemy */
t_enemy	*ft_enemynew(int x, int y)
{
	t_enemy	*enem;

	enem = malloc(sizeof(t_enemy));
	if (!enem)
		return (NULL);
	enem->x = x;
	enem->y = y;
	enem->dir = 1;
	enem->ice_ptr = NULL;
	enem->next = NULL;
	return (enem);
}

/* Add the new enemy to a list of enemies*/
void	ft_enemyadd_back(t_enemy **first, t_enemy *second)
{
	t_enemy	*aux;

	aux = *first;
	if (*first)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = second;
	}
	else
		*first = second;
}
