/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:11:44 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/24 20:16:25 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	small_error(char *msg)
{
	write(2, "Error:\n", 7);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	error_map(t_game *game, char *msg)
{
	free_map(&game->map);
	write(2, "Error:\n", 7);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	error(t_game *game, char *msg)
{
	free_all(game);
	write(2, "Error:\n", 7);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
