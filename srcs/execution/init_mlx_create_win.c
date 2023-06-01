/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_create_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:17:57 by gclement          #+#    #+#             */
/*   Updated: 2023/06/01 17:06:36 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx_create_win(t_env *env)
{
	t_img		img;

	env->windows.mlx = mlx_init();
	// if (!win->mlx) !!!!!!!!!! A actualise
	// 	free_and_exit(win);
	env->windows.win = mlx_new_window(env->windows.mlx, 1920, 1080, "cub3d");
	img.img = mlx_new_image(env->windows.mlx, 1920, 1080);
	//if (!img.img)
	//error
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// if (!img.addr || !win->win) !!!!!!!!!! A actualise
	// 	free_and_exit(win);
	env->img = img;
	//draw_all_lines(win->img, win);
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, env->img.img, 0, 0);
	mlx_hook(env->windows.win, 2, 1L << 0, key_hook, env);
	mlx_hook(env->windows.win, 17, 1L << 8, mlx_close, env);
	// mlx_loop(env->windows.mlx);
}
