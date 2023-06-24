/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_images_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:44:42 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 20:04:25 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	charge_image_collectibles(t_game *game)
{
	charge_image(game, &game->img_collect.collect_1, COLLECT_1);
	charge_image(game, &game->img_collect.collect_2, COLLECT_2);
	charge_image(game, &game->img_collect.collect_3, COLLECT_3);
}

void	charge_image_ennemi(t_game *game)
{
	charge_image(game, &game->img_ennemi.ennemi_1, ENNEMI_1);
	charge_image(game, &game->img_ennemi.ennemi_2, ENNEMI_2);
	charge_image(game, &game->img_ennemi.ennemi_3, ENNEMI_3);
	charge_image(game, &game->img_ennemi.ennemi_4, ENNEMI_4);
}

void	charge_image_exit(t_game *game)
{
	charge_image(game, &game->img_exit.exit_1, EXIT_1);
	charge_image(game, &game->img_exit.exit_2, EXIT_2);
	charge_image(game, &game->img_exit.exit_3, EXIT_3);
	charge_image(game, &game->img_exit.exit_4, EXIT_4);
}

void	charge_image_player(t_game *game)
{
	charge_image(game, &game->img_player.backfacing[0], PLAYER_BFACING_IDLE);
	charge_image(game, &game->img_player.backfacing[1], PLAYER_BFACING_WALK_1);
	charge_image(game, &game->img_player.backfacing[2], PLAYER_BFACING_IDLE);
	charge_image(game, &game->img_player.rightfacing[0], PLAYER_RFACING_IDLE);
	charge_image(game, &game->img_player.rightfacing[1], PLAYER_RFACING_WALK_1);
	charge_image(game, &game->img_player.rightfacing[2], PLAYER_RFACING_IDLE);
	charge_image(game, &game->img_player.frontfacing[0], PLAYER_FFACING_IDLE);
	charge_image(game, &game->img_player.frontfacing[1], PLAYER_FFACING_WALK_1);
	charge_image(game, &game->img_player.frontfacing[2], PLAYER_FFACING_IDLE);
	charge_image(game, &game->img_player.leftfacing[0], PLAYER_LFACING_IDLE);
	charge_image(game, &game->img_player.leftfacing[1], PLAYER_LFACING_WALK_1);
	charge_image(game, &game->img_player.leftfacing[2], PLAYER_LFACING_IDLE);
}

void	charge_image_wall(t_game *game)
{
	charge_image(game, &game->img_wall.wall_1, WALL_1);
	charge_image(game, &game->img_wall.wall_2, WALL_2);
	charge_image(game, &game->img_wall.wall_3, WALL_3);
}
