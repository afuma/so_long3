/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:08:01 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 19:38:53 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_exitable(t_game *game)
{
	t_data	*tmp_map;
	int		find;

	find = 0;
	tmp_map = (t_data *) malloc(sizeof(t_data));
	if (!tmp_map)
		error(game, "Memory allocation of tmp_map failed !\n");
	tmp_map->tab = make_area(game->map->tab, \
		game->map->size.x, game->map->size.y);
	cpy_map(game->map, tmp_map);
	f_efill(tmp_map, tmp_map->player.pos.y, tmp_map->player.pos.x);
	find = tmp_map->find;
	free_map(&tmp_map);
	if (find)
		return (1);
	else
		return (0);
}

void	f_efill(t_data *map, int row, int col)
{
	if (row < 0 || col < 0 || row >= map->size.y || col >= map->size.x || \
		map->tab[row][col] == '1' || \
		map->tab[row][col] == 'F' || map->find == 1)
		return ;
	if (map->tab[row][col] == '0' || map->tab[row][col] == 'P' ||
		map->tab[row][col] == 'C' || map->tab[row][col] == 'M')
			map->tab[row][col] = 'F';
	if (map->tab[row][col] == 'E')
	{
		map->find = 1;
		map->tab[row][col] = 'F';
	}
	f_efill(map, row -1, col);
	f_efill(map, row +1, col);
	f_efill(map, row, col - 1);
	f_efill(map, row, col + 1);
}
