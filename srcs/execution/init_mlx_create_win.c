/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_create_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:17:57 by gclement          #+#    #+#             */
/*   Updated: 2023/06/09 13:22:52 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	create_all_textures_img(t_env *env)
{
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, \
		env->img.img, 0, 0);
	env->data.textures_img[0] = create_textures_img(\
		"./textures/north.xpm", &env->windows);
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, \
		env->img.img, 0, 0);
	env->data.textures_img[1] = create_textures_img(\
		"./textures/east.xpm", &env->windows);
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, \
		env->img.img, 0, 0);
	env->data.textures_img[2] = create_textures_img(\
		"./textures/south.xpm", &env->windows);
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, \
		env->img.img, 0, 0);
	env->data.textures_img[3] = create_textures_img(\
		"./textures/west.xpm", &env->windows);
}

void	init_mlx_create_win(t_env *env)
{
	t_img		img;

	env->windows.mlx = mlx_init();
	if (!env->windows.mlx)
		free_parsing(&env->data);
	env->windows.win = mlx_new_window(\
		env->windows.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	img.img = mlx_new_image(env->windows.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img.img)
	{
		free(env->windows.mlx);
		free_parsing(&env->data);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (!img.addr)
	{
		free(env->windows.mlx);
		free(img.img);
		free_parsing(&env->data);
	}
	env->img = img;
	draw_map(env);
	env->data.p_pos_y = (env->data.p_pos_y * TILE_SIZE) + TILE_SIZE / 2;
	env->data.p_pos_x = (env->data.p_pos_x * TILE_SIZE) + TILE_SIZE / 2;
	draw_player_pos(env->data.p_pos_y, env->data.p_pos_x, &env->img);
	mlx_put_image_to_window(env->windows.mlx, env->windows.win,
		env->img.img, 0, 0);
	create_all_textures_img(env);
	mlx_hook(env->windows.win, 2, 1L << 0, key_hook, env);
	mlx_hook(env->windows.win, 17, 1L << 8, mlx_close, env);
}

