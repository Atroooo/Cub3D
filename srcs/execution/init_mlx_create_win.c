/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_create_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:17:57 by gclement          #+#    #+#             */
/*   Updated: 2023/06/20 17:34:40 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_game(t_env *env)
{
	create_all_textures_img(env);
	draw_map(env);
	env->data.p_pos_y = (env->data.p_pos_y * TILE_SIZE) + TILE_SIZE / 2;
	env->data.p_pos_x = (env->data.p_pos_x * TILE_SIZE) + TILE_SIZE / 2;
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, \
		env->img.img, 0, 0);
	mlx_loop_hook(env->windows.mlx, refresh_img, env);
	mlx_hook(env->windows.win, 2, 1L << 0, key_hook, env);
	mlx_hook(env->windows.win, 17, 1L << 8, mlx_close, env);
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
	init_game(env);
}
