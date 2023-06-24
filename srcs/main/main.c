/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:20:46 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 20:19:57 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// void print_map(t_data *map)
// {
// 	for (int i = 0; i < map->size.y; i++)
// 	{
// 		for (int j = 0; j < map->size.x; j++)
// 		{
// 			if (j != 0)
// 				printf(" ");
// 			printf("%c", map->tab[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		small_error("Invalid number of arguments !\n");
	game.filename = argv[1];
	init_game(&game);
	verif_map(&game);
	if (!is_exitable(&game))
		error_map(&game, "No valid path for exit on this map was found !\n");
	if (!is_collectables(&game))
		error_map(&game, "No valid path for collectibles !\n");
	init_mlx(&game);
	charge_images(&game);
	draw_map(&game);
	mlx_loop_hook(game.mlx_ptr, draw_map, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
