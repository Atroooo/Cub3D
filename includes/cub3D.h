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
# define WALL_H			2600
# define OPP_H			1250
# define OPP_W			900
# define D_E			0.50
# define E_H			500
# define RAD			0.01745329
# define MINI_MAP_SIZE	10
# define HITBOX	0.4

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

/* Free */
void			free_char_array(char **array);
void			free_windows_struct(t_env *env);
void	        free_img(t_env *env);

/* Mini_map */
void			draw_map(t_env *env);
void			draw_tile(t_vector_2d pixel, uint32_t color, t_img *img);
void			draw_wall(t_ray ray, t_env *env, float x);
void			draw_column(float distance, t_env *env, float *cam_x);
void			frame_gun(t_env *env);
unsigned int	pixel_brightness(float distance, unsigned int color);

/* OPPS */
void			frame_opps(t_env *env, t_opps *opp);
void			draw_opps_sprite(t_env *env, t_opps opp);
void			malloc_opp_arr(t_data *data);
void			set_ray_opp(t_ray ray, t_data *data);
void			set_door(t_ray *ray, t_bools is_open);
int				search_opp(int y, int x, t_data data);
void			game_over_screen(t_env *env);
void			move_opp(t_env *env, t_opps *opp);

/* Raycasting */
void	        init_ray(t_ray *ray, t_data *data, float d_x, float d_y);
void			dda(float d_x, float d_y, t_env *env, t_ray *ray);
void			init_ray(t_ray *ray, t_data *data, float d_x, float d_y);
void			raycasting(t_env *env);

/* Pixel print */
void			my_mlx_put_line(t_img *img, int p1, int p2, uint32_t color);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
char			*get_pixel_in_texture(t_img data, int x, int y);

/*Move*/
void			move(t_env *env, t_data *data, int keycode);
void			rotate(t_data *data, int keycode);
void			open_door(t_env *env, t_data *data);
void			shoot(t_env	*env);

/* Collisions */
int				collision(float pos_x, float pos_y, t_env *env, char c);

#endif