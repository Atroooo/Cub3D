/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:45:49 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 21:45:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_HEIGHT		1080
# define WIN_WIDTH		1920
# define TILE_SIZE  	20
# define MOVE_SPEED 	3
# define M_PI       	3.14159265358979323846
# define WALL_H			2200
# define OPP_H			1250
# define D_E			0.50
# define E_H			500
# define RAD			0.01745329
# define MINI_MAP_SIZE	10

# include "../minilibx_linux/mlx.h"
# include "../libft/header/libft.h"
# include "struct.h"
# include "keys.h"
# include "keyhook_functions.h"
# include "parsing.h"
# include "windows.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>


void	free_char_array(char **array);
void	free_windows_struct(t_env *env);
void	print_param(t_data *map_info);

/* mini_map */
void	draw_map(t_env *env);
void	draw_tile(t_vector_2d pixel, uint32_t color, t_img *img);
void	draw_player_pos(float y, float x, t_vector_2f p_index, t_img *img);
float	calc_radius(t_env *env, float dy, float dx);
void	draw_wall(t_ray ray, t_env *env, float x);
void	draw_column(float distance, t_env *env, float *cam_x);
void	frame_gun(t_env *env);
void	frame_opps(t_env *env, t_sprite *opp);
void	set_door(t_ray *ray, t_bools is_open);

void	dda(float d_x, float d_y, t_env *env, t_ray *ray);
void	raycasting(t_env *env);

void	my_mlx_put_line(t_img *img, int p1, int p2, uint32_t color);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
char	*get_pixel_in_texture(t_img data, int x, int y);

/*Move*/
void	move(t_env *env, t_data *data, int keycode);
void	rotate(t_env *env, t_data *data, int keycode);
void 	open_door(t_env *env, t_data *data);

/*Collisions*/
int		collision(float pos_x, float pos_y, t_env *env, char c);

#endif