/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:48:15 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 21:06:50 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	verif_map(t_game *game)
{
	if (!is_map_rectangle(game->map))
		error_map(game, "Map is not rectangular !\n");
	if (!is_valid_elems(game->map))
		error_map(game, "Elements in the map is not correct !\n");
	if (!is_exist_elem(game->map, 'E'))
		error_map(game, "Element E is missing from the map !\n");
	if (!is_exist_elem(game->map, 'P'))
		error_map(game, "Element P is missing from the map !\n");
	if (!is_exist_elem(game->map, 'C'))
		error_map(game, "Element C is missing from the map !\n");
	if (!is_map_duplicates(game->map, 'P'))
		error_map(game, "Element P is double in the map !\n");
	if (!is_map_duplicates(game->map, 'E'))
		error_map(game, "Element E is double in the map !\n");
	if (!is_map_close(game->map, '1'))
		error_map(game, "The map is not close !\n");
}

int	compt_elems(t_game *game, char letter)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	j = 0;
	cpt = 0;
	while (i < game->map->size.y)
	{
		while (j < game->map->size.x)
		{
			if (game->map->tab[i][j] == letter)
				cpt++;
			j++;
		}
		i++;
		j = 0;
	}
	return (cpt);
}
