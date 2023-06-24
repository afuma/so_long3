/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_images_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:44:40 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 20:01:57 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	charge_image(t_game *game, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, \
		path, &game->img_ppixel.x, &game->img_ppixel.y);
	if (img->mlx_img == NULL)
	{
		write(2, path, ft_strlen(path));
		error(game, "An image can not be loaded by the MLX !");
	}
}

void	charge_images(t_game *game)
{
	game->img_ppixel.x = game->width / game->map->size.x;
	game->img_ppixel.y = game->height / game->map->size.y;
	check_path_images(game);
	charge_image_collectibles(game);
	charge_image_ennemi(game);
	charge_image_exit(game);
	charge_image_player(game);
	charge_image_wall(game);
	charge_image(game, &game->img_ground, GROUND);
}
