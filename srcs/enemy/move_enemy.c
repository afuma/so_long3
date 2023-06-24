/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:22:59 by blax              #+#    #+#             */
/*   Updated: 2023/06/24 20:00:32 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_enemy(t_game *game)
{
	int	k;

	k = 0;
	while (k < game->map->max_enemy)
	{
		next_move_enemy(game, k);
		k++;
	}
}

void	enemy_on_player(t_game *game, int init_i, int init_j)
{
	if (game->map->tab[init_i][init_j] == 'P')
	{
		free_all(game);
		write(1, "you lose.. !\n", 14);
		exit (EXIT_SUCCESS);
	}
}

void	enemy_pass_on_object(t_game *game, int init_i, int init_j, int k)
{
	if (game->map->enemy[k].on_collectible == 1)
	{
		game->map->tab[init_i][init_j] = 'C';
		game->map->enemy[k].on_collectible = 0;
	}
	else if (game->map->enemy[k].on_exit == 1)
	{
		game->map->tab[init_i][init_j] = 'E';
		game->map->enemy[k].on_exit = 0;
	}
	else
		game->map->tab[init_i][init_j] = '0';
}

void	enemy_path(t_game *game, int init_i, int init_j, int k)
{
	if (game->map->tab[init_i][init_j] == '0' ||
		game->map->tab[init_i][init_j] == 'C' ||
		game->map->tab[init_i][init_j] == 'E')
	{
		if (game->map->tab[init_i][init_j] == 'C')
			game->map->enemy[k].on_collectible = 1;
		if (game->map->tab[init_i][init_j] == 'E')
			game->map->enemy[k].on_exit = 1;
		game->map->tab[init_i][init_j] = 'M';
		game->map->enemy[k].start.x = init_j;
		game->map->enemy[k].start.y = init_i;
	}
}
