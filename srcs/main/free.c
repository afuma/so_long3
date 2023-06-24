/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:11:44 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 20:16:53 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(t_data **map)
{
	int	i;

	i = 0;
	while (i < (*map)->size.y)
	{
		free((*map)->tab[i]);
		(*map)->tab[i] = NULL;
		i++;
	}
	free((*map)->tab);
	(*map)->tab = NULL;
	free(*map);
	*map = NULL;
}

void	free_images(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	destroy_images(game);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

void	free_all(t_game *game)
{
	free_images(game);
	free_map(&game->map);
}
