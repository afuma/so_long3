/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:41:48 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 20:13:31 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_path_image_collectibles(t_game *game)
{
	check_path_image(game, COLLECT_1);
	check_path_image(game, COLLECT_2);
	check_path_image(game, COLLECT_3);
}

void	check_path_image_ennemi(t_game *game)
{
	check_path_image(game, ENNEMI_1);
	check_path_image(game, ENNEMI_2);
	check_path_image(game, ENNEMI_3);
	check_path_image(game, ENNEMI_4);
}

void	check_path_image_exit(t_game *game)
{
	check_path_image(game, EXIT_1);
	check_path_image(game, EXIT_2);
	check_path_image(game, EXIT_3);
	check_path_image(game, EXIT_4);
}

void	check_path_image_player(t_game *game)
{
	check_path_image(game, PLAYER_BFACING_IDLE);
	check_path_image(game, PLAYER_BFACING_WALK_1);
	check_path_image(game, PLAYER_BFACING_WALK_2);
	check_path_image(game, PLAYER_FFACING_IDLE);
	check_path_image(game, PLAYER_FFACING_WALK_1);
	check_path_image(game, PLAYER_FFACING_WALK_2);
	check_path_image(game, PLAYER_LFACING_IDLE);
	check_path_image(game, PLAYER_LFACING_WALK_1);
	check_path_image(game, PLAYER_LFACING_WALK_2);
	check_path_image(game, PLAYER_RFACING_IDLE);
	check_path_image(game, PLAYER_RFACING_WALK_1);
	check_path_image(game, PLAYER_RFACING_WALK_2);
}

void	check_path_image_wall(t_game *game)
{
	check_path_image(game, WALL_1);
	check_path_image(game, WALL_2);
	check_path_image(game, WALL_3);
}
