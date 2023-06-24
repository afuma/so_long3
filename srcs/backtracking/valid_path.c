/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:58:11 by blax              #+#    #+#             */
/*   Updated: 2023/06/24 19:40:17 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	cpy_map(t_data *map, t_data *tmp_map)
{
	tmp_map->size.y = map->size.y;
	tmp_map->size.x = map->size.x;
	cpy_map_player(map, tmp_map);
	tmp_map->collectibles = map->collectibles;
	tmp_map->max_collectibles = map->max_collectibles;
	tmp_map->find = map->find;
}

void	cpy_map_player(t_data *map, t_data *tmp_map)
{
	tmp_map->player.pos.y = map->player.pos.y;
	tmp_map->player.pos.x = map->player.pos.x;
	tmp_map->player.on_exit = map->player.on_exit;
	tmp_map->player.moved = map->player.moved;
	tmp_map->player.moves = map->player.moves;
	tmp_map->player.speed = map->player.speed;
}

char	**make_area(char **zone, int x, int y)
{
	char	**area;
	int		i;
	int		j;

	i = 0;
	j = 0;
	area = (char **) malloc(sizeof(char *) * y);
	while (i < y)
	{
		area[i] = (char *) malloc(sizeof(char) * x);
		while (j < x)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (area);
}
