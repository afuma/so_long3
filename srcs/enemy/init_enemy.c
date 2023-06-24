/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:27:45 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 19:55:18 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_enemy(t_game *game)
{
	int	k;

	init_enemy_on_map(game);
	k = 0;
	while (k < game->map->max_enemy)
	{
		game->map->enemy[k].on_exit = 0;
		game->map->enemy[k].on_collectible = 0;
		k++;
	}
}

void	init_enemy_on_map(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < game->map->size.y)
	{
		while (j < game->map->size.x)
		{
			if (game->map->tab[i][j] == 'M')
			{
				game->map->enemy[k].start.y = i;
				game->map->enemy[k].start.x = j;
				k++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (k >= 10)
		error_map(game, "Too much ennemies detected in the map (>10 M) !\n");
}

int	find_next(t_game *game, int init_i, int init_j)
{
	if (game->map->tab[init_i][init_j] == '0' ||
		game->map->tab[init_i][init_j] == 'C' ||
		game->map->tab[init_i][init_j] == 'P' ||
		game->map->tab[init_i][init_j] == 'E')
	{
		return (1);
	}
	return (0);
}

void	init_dir_enemy(t_game *game)
{
	game->map->dx[0] = 1;
	game->map->dx[1] = -1;
	game->map->dx[2] = 0;
	game->map->dx[3] = 0;
	game->map->dy[0] = 0;
	game->map->dy[1] = 0;
	game->map->dy[2] = -1;
	game->map->dy[3] = 1;
}

void	next_move_enemy(t_game *game, int k)
{
	int	init_i;
	int	init_j;
	int	suiv_i;
	int	suiv_j;
	int	i;

	i = 0;
	init_i = game->map->enemy[k].start.y;
	init_j = game->map->enemy[k].start.x;
	while (i < 4)
	{
		suiv_i = init_i + game->map->dy[i];
		suiv_j = init_j + game->map->dx[i];
		if (find_next(game, suiv_i, suiv_j))
		{
			enemy_pass_on_object(game, init_i, init_j, k);
			enemy_on_player(game, suiv_i, suiv_j);
			enemy_path(game, suiv_i, suiv_j, k);
			break ;
		}
		i++;
	}
}
