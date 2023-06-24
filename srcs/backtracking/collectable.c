/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:08:51 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 19:37:28 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_collectables(t_game *game)
{
	t_data	*tmp_map;
	int		collectibles;

	collectibles = 0;
	tmp_map = (t_data *) malloc(sizeof(t_data));
	if (!tmp_map)
		error(game, "Memory allocation of tmp_map failed !\n");
	tmp_map->tab = make_area(game->map->tab, \
			game->map->size.x, game->map->size.y);
	cpy_map(game->map, tmp_map);
	f_cfill(tmp_map, tmp_map->player.pos.y, tmp_map->player.pos.x);
	collectibles = tmp_map->collectibles;
	free_map(&tmp_map);
	if (game->map->max_collectibles == collectibles)
		return (1);
	else
		return (0);
}

void	f_cfill(t_data *map, int row, int col)
{
	if (row < 0 || col < 0 || row >= map->size.y || col >= map->size.x || \
		map->tab[row][col] == '1' || \
		map->tab[row][col] == 'F' || map->collectibles == map->max_collectibles)
		return ;
	if (map->tab[row][col] == '0' || map->tab[row][col] == 'P' ||
		map->tab[row][col] == 'E' || map->tab[row][col] == 'M')
			map->tab[row][col] = 'F';
	if (map->tab[row][col] == 'C')
	{
		map->collectibles += 1;
		map->tab[row][col] = 'F';
	}
	f_cfill(map, row -1, col);
	f_cfill(map, row +1, col);
	f_cfill(map, row, col - 1);
	f_cfill(map, row, col + 1);
}
