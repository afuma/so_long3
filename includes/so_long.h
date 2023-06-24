/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:13:47 by blax              #+#    #+#             */
/*   Updated: 2023/06/23 20:32:56 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>

# include "mlx_header.h"
# include "../libft/libft.h"
# include "get_next_line.h"

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

// void print_map(t_data *map);


// MAIN
// ------------------------------------------------------------ //
// error.c
int small_error(char *msg);
int error_map(t_game *game, char *msg);
int error(t_game *game, char *msg);

// free.c
void free_map(t_data **map);
void free_images(t_game *game);
void free_all(t_game *game);

// move.c
void move_player_1(t_game *game, int direction, int offset_x, int offset_y);
void	move_player_2(t_game *game, int offset_x, int offset_y);
void	move_player_3(t_game *game, int direction, int offset_x, int offset_y);
void move(t_game *game, int direction);
int	handle_keypress(int keycode, t_game *game);

// render.c
int	put_string_moves(t_game *game);
int draw_map(t_game *game);
void draw_image_1(t_game *game, int i, int j, char letter);
void draw_image_2(t_game *game, int i, int j, char letter);

// init_1.c
void init_game(t_game *game);
void init_mlx(t_game *game);
void init_map(t_game *game);

// init_2.c
void init_offset_img_player(t_game *game);
void init_var_map(t_game *game);
void init_size(t_game *game);
void init_player(t_game *game);
void init_player_on_map(t_game *game);

// utils.c
// void print_enemies(t_game *game);
int	check_map_extension(char *str, char *ext);
void update_player(t_game *game, int direction, int i, int j);
void finish_move(t_game *game, int i, int j);
void update_player_code(t_game *game, int direction);
void put_image(t_game *game, t_img *img, int j, int i);

// ------------------------------------------------------------ //


// IMAGES
// ------------------------------------------------------------ //
// check_path_1.c
void check_path_image(t_game *game, char *path);
void check_path_images(t_game *game);

// check_path_2.c
void check_path_image_collectibles(t_game *game);
void check_path_image_ennemi(t_game *game);
void check_path_image_exit(t_game *game);
void check_path_image_player(t_game *game);
void check_path_image_wall(t_game *game);

// charge_images_1.c
void charge_image(t_game *game, t_img *img, char *path);
void charge_images(t_game *game);

// charge_images_2.c
void charge_image_collectibles(t_game *game);
void charge_image_ennemi(t_game *game);
void charge_image_exit(t_game *game);
void charge_image_player(t_game *game);
void charge_image_wall(t_game *game);

// destroy_images_1.c
void destroy_image(t_game *game, t_img *img);
void destroy_images(t_game *game);

// destroy_images_2.c
void destroy_image_collectibles(t_game *game);
void destroy_image_ennemi(t_game *game);
void destroy_image_exit(t_game *game);
void destroy_image_player(t_game *game);
void destroy_image_wall(t_game *game);

// put_image_1.c
void update_sprite(t_game *game, int j, int i, t_img img[3]);
void put_image_player_1(t_game *game, int j, int i);
void put_image_player_2(t_game *game, int i, int j);
// ------------------------------------------------------------ //

// ENEMY
// ------------------------------------------------------------ //
// init_enemy.c
void init_enemy(t_game *game);
void init_enemy_on_map(t_game *game);
int find_next(t_game *game, int init_i, int init_j);
void init_dir_enemy(t_game *game);
void next_move_enemy(t_game *game, int k);

// move_enemy.c
void update_enemy(t_game *game);
void enemy_on_player(t_game *game, int init_i, int init_j);
void enemy_pass_on_object(t_game *game, int init_i, int init_j, int k);
void enemy_path(t_game *game, int init_i, int init_j, int k);
// ------------------------------------------------------------ //


// PARSING
// ------------------------------------------------------------ //
// valid_map_1.c
int is_valid_elems(t_data *map);
int is_exist_elem(t_data *map, char letter);
int is_map_rectangle(t_data *map);
int is_map_duplicates(t_data *map, char letter);
int is_map_close(t_data *map, char letter);

// valid_map_2.c
void verif_map(t_game *game);
int compt_elems(t_game *game, char letter);
// ------------------------------------------------------------ //


// BACKTRACKING
// ------------------------------------------------------------ //
// valid_path.c
void cpy_map(t_data *map, t_data *tmp_map);
void cpy_map_player(t_data *map, t_data *tmp_map);
char **make_area(char **zone, int _x, int _y);

// exitable.c
int is_exitable(t_game *game);
void f_efill(t_data *map, int row, int col);

// collectable.c
int is_collectables(t_game *game);
void f_cfill(t_data *map, int row, int col);

// mechable.c
int is_mechable(t_game *game);
void f_mfill(t_data *map, int row, int col);
// ------------------------------------------------------------ //

#endif
