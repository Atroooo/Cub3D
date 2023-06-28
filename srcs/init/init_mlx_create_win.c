/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_create_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:17:57 by gclement          #+#    #+#             */
/*   Updated: 2023/06/28 15:19:42 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_game(t_env *env)
{
	env->data.is_pressed = 0;
	create_all_textures_img(env);
	draw_map(env);
	env->data.p_pos_y = (env->data.p_pos_y * TILE_SIZE) + TILE_SIZE / 2;
	env->data.p_pos_x = (env->data.p_pos_x * TILE_SIZE) + TILE_SIZE / 2;
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, \
		env->img.img, 0, 0);
	mlx_loop_hook(env->windows.mlx, refresh_img, env);
	mlx_hook(env->windows.win, 2, 1L << 0, key_hook, env);
	mlx_hook(env->windows.win, 3, 1L << 1, key_hook_unpressed, env);
	mlx_hook(env->windows.win, 17, 1L << 8, mlx_close, env);
	mlx_mouse_hide(env->windows.mlx, env->windows.win);
	mlx_mouse_move(env->windows.mlx, env->windows.win, \
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_hook(env->windows.win, 6, 1L << 6, mouse_hook, env);
	mlx_mouse_hook(env->windows.win, mouse_hook_button, env);
}

static void	handle_mlx_errors(t_env *env, int s, t_img img)
{
	if (s == 1)
		mlx_destroy_image(env->windows.mlx, img.img);
	mlx_destroy_window(env->windows.mlx, env->windows.win);
	mlx_destroy_display(env->windows.mlx);
	free(env->windows.mlx);
	free_parsing(&env->data);
}

void	init_mlx_create_win(t_env *env)
{
	t_img		img;

	env->windows.mlx = mlx_init();
	if (!env->windows.mlx)
		free_parsing(&env->data);
	env->windows.win = mlx_new_window(\
		env->windows.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!env->windows.win)
	{
		mlx_destroy_display(env->windows.mlx);
		free_windows_struct(env);
	}
	img.img = mlx_new_image(env->windows.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img.img)
		handle_mlx_errors(env, 0, img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (!img.addr)
		handle_mlx_errors(env, 1, img);
	env->img = img;
	init_game(env);
}
