/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:33:33 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 21:44:49 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_player_1(t_game *game, int direction, int offset_x, int offset_y)
{
	int	i;
	int	j;

	i = game->map->player.pos.y + offset_y;
	j = game->map->player.pos.x + offset_x;
	if (i <= 0 || j <= 0 || i >= game->map->size.y - 1 || \
		j >= game->map->size.x - 1 || game->map->tab[i][j] == '1')
		return ;
	move_player_2(game, offset_x, offset_y);
	move_player_3(game, direction, offset_x, offset_y);
	finish_move(game, i, j);
}

void	move_player_2(t_game *game, int offset_x, int offset_y)
{
	int	i;
	int	j;

	i = game->map->player.pos.y + offset_y;
	j = game->map->player.pos.x + offset_x;
	if (game->map->tab[i][j] == '0' || game->map->tab[i][j] == 'C')
	{
		if (game->map->tab[i][j] == 'C')
			game->map->collectibles++;
		if (game->map->player.on_exit == 1)
		{
			game->map->tab[i - offset_y][j - offset_x] = 'E';
			game->map->player.on_exit = 0;
		}
		else
			game->map->tab[i - offset_y][j - offset_x] = '0';
	}
}

void	move_player_3(t_game *game, int direction, int offset_x, int offset_y)
{
	int	i;
	int	j;

	i = game->map->player.pos.y + offset_y;
	j = game->map->player.pos.x + offset_x;
	if (game->map->tab[i][j] == 'E' &&
		game->map->collectibles != game->map->max_collectibles)
	{
		game->map->tab[i - offset_y][j - offset_x] = '0';
		game->map->player.on_exit = 1;
	}
	if (game->map->tab[i][j] == '0' || game->map->tab[i][j] == 'C' || \
		(game->map->tab[i][j] == 'E' &&
		game->map->collectibles != game->map->max_collectibles))
	{
		update_player(game, direction, i, j);
		update_enemy(game);
	}
}

void	move(t_game *game, int direction)
{
	if (direction == UP)
		move_player_1(game, UP, 0, -1);
	if (direction == RIGHT)
		move_player_1(game, RIGHT, 1, 0);
	if (direction == DOWN)
		move_player_1(game, DOWN, 0, 1);
	if (direction == LEFT)
		move_player_1(game, LEFT, -1, 0);
	game->map->player.moves += 1;
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_a || keycode == XK_Left)
		move(game, LEFT);
	if (keycode == XK_d || keycode == XK_Right)
		move(game, RIGHT);
	if (keycode == XK_w || keycode == XK_Up)
		move(game, UP);
	if (keycode == XK_s || keycode == XK_Down)
		move(game, DOWN);
	if (keycode == XK_Escape)
	{
		free_all(game);
		write(1, "You have just left the game !\n", 31);
		exit (EXIT_SUCCESS);
	}
	if (keycode == XK_Control_L || keycode == XK_Control_R)
		game->ctrl_pressed = 1;
	else if (keycode == XK_c && game->ctrl_pressed)
	{
		free_all(game);
		write(1, "You have just left the game with Ctrl + C !\n", 44);
		exit(EXIT_SUCCESS);
	}
	else
		game->ctrl_pressed = 0;
	return (0);
}
