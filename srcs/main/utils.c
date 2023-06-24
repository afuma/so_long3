/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:49:01 by blax              #+#    #+#             */
/*   Updated: 2023/06/24 21:43:12 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_map_extension(char *str, char *ext)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str) - 4;
	j = 0;
	while (str[i] && ext[j] && str[i] == ext[j])
	{
		i++;
		j++;
	}
	if (j == 4)
		return (1);
	return (0);
}

void	update_player(t_game *game, int direction, int i, int j)
{
	game->map->tab[i][j] = 'P';
	game->map->player.pos.x = j;
	game->map->player.pos.y = i;
	game->map->player.moved = 1;
	game->current_sprite = 0;
	update_player_code(game, direction);
}

void	finish_move(t_game *game, int i, int j)
{
	if (game->map->tab[i][j] == 'M')
	{
		free_all(game);
		write(1, "you lose.. !\n", 14);
		exit (EXIT_SUCCESS);
	}
	if (game->map->tab[i][j] == 'E' &&
		game->map->collectibles == game->map->max_collectibles)
	{
		free_all(game);
		write(1, "SUCCESS !\n", 11);
		exit (EXIT_SUCCESS);
	}
}

void	update_player_code(t_game *game, int direction)
{
	if (direction == UP)
		game->img_player.code = 1;
	if (direction == RIGHT)
		game->img_player.code = 2;
	if (direction == DOWN)
		game->img_player.code = 3;
	if (direction == LEFT)
		game->img_player.code = 4;
}

void	put_image(t_game *game, t_img *img, int j, int i)
{
	mlx_put_image_to_window(
		game->mlx_ptr, game->win_ptr, img->mlx_img, j, i);
}
