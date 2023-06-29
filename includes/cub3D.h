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
# define D_E			0.50
# define E_H			500
# define RAD			0.01745329
# define MINI_MAP_SIZE	10
# define HITBOX			0.3

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
void	free_char_array(char **array);
void	free_windows_struct(t_env *env);

/* raycasting */
void	init_ray(t_ray *ray, t_env *env, float d_x, float d_y);
t_ray	dda(float d_x, float d_y, t_env *env);
void	raycasting(t_env *env);
void	draw_wall(t_ray ray, t_env *env, float x);

/* Pixel print*/
void	my_mlx_put_line(t_img *img, int p1, int p2, uint32_t color);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
char	*get_pixel_in_texture(t_img data, int x, int y);

/* Move */
void	move(t_env *env, t_data *data, int keycode);
void	rotate(t_env *env, t_data *data, int keycode);

/*Collisions*/
int		collision(float pos_x, float pos_y, t_env *env, char c);

#endif