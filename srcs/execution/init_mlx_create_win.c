/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_create_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:17:57 by gclement          #+#    #+#             */
/*   Updated: 2023/06/02 13:36:12 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx_create_win(t_env *env)
{
	t_img		img;

	env->windows.mlx = mlx_init();
	// if (!win->mlx) !!!!!!!!!! A actualise
	// 	free_and_exit(win);
	env->windows.win = mlx_new_window( \
		env->windows.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	img.img = mlx_new_image(env->windows.mlx, WIN_WIDTH, WIN_HEIGHT);
	//if (!img.img)
	//error
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// if (!img.addr || !win->win) !!!!!!!!!! A actualise
	// 	free_and_exit(win);
	env->img = img;
	draw_map(env);
	env->data.p_pos_y = (env->data.p_pos_y * TILE_SIZE) + TILE_SIZE / 2;
	env->data.p_pos_x = (env->data.p_pos_x * TILE_SIZE) + TILE_SIZE / 2;
	draw_player_pos(env->data.p_pos_y, env->data.p_pos_x, &env->img);
	mlx_put_image_to_window(env->windows.mlx, env->windows.win,
		env->img.img, 0, 0);
	mlx_hook(env->windows.win, 2, 1L << 0, key_hook, env);
	mlx_hook(env->windows.win, 17, 1L << 8, mlx_close, env);
}
