/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:06:07 by gclement          #+#    #+#             */
<<<<<<< HEAD:srcs/execution/refresh_img.c
/*   Updated: 2023/06/26 18:19:44 by gclement         ###   ########.fr       */
=======
/*   Updated: 2023/06/26 14:42:02 by lcompieg         ###   ########.fr       */
>>>>>>> a551f3f0def2cba5eaad530f7aa1ffb9ce2972b9:srcs/draw/refresh_img.c
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

<<<<<<< HEAD:srcs/execution/refresh_img.c
static void	check_which_opp_display(t_env *env, t_opps *opps)
=======
static void	handle_mlx_errors(t_env *env, int s, t_img img)
>>>>>>> a551f3f0def2cba5eaad530f7aa1ffb9ce2972b9:srcs/draw/refresh_img.c
{
	int	i;

	i = 0;
<<<<<<< HEAD:srcs/execution/refresh_img.c
	while (i < env->data.opp_nb)
	{
		if (opps[i].in_fov == TRUE)
		{
			if (opps[i].ray.length - opps[i].len_sou < 1.5 && opps[i].pv > 0)
				env->data.game_over = TRUE;
			else
			{
				frame_opps(env, &opps[i]);
				opps[i].in_fov = FALSE;
				opps[i].frame++;
				opps[i].x = -1;
				env->data.ray_opp.active = FALSE;
				if (opps[i].frame == 15 && opps[i].pv > 0)
					opps[i].len_sou += 0.8;
				if (opps[i].pv <= 0 && opps[i].frame == 40)
					env->data.map_data.map[opps[i].index.y][opps[i].index.x] = '0';
			}
		}
		i++;
	}
=======
	while (i < 4)
	{
		if (env->windows.mlx && env->data.textures_img[i].img != NULL)
			mlx_destroy_image(env->windows.mlx, \
				env->data.textures_img[i].img);
		i++;
	}
	if (s == 0)
	{
		mlx_destroy_window(env->windows.mlx, env->windows.win);
		mlx_destroy_display(env->windows.mlx);
	}
	if (s == 1)
	{
		mlx_destroy_image(env->windows.mlx, img.img);
		mlx_destroy_window(env->windows.mlx, env->windows.win);
		mlx_destroy_display(env->windows.mlx);
	}
	free(env->windows.mlx);
	free_parsing(&env->data);
>>>>>>> a551f3f0def2cba5eaad530f7aa1ffb9ce2972b9:srcs/draw/refresh_img.c
}

int	refresh_img(t_env *env)
{
	mlx_destroy_image(env->windows.mlx, env->img.img);
	env->img.img = mlx_new_image(env->windows.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!env->img.img)
		handle_mlx_errors(env, 0, env->img);
	env->img.addr = mlx_get_data_addr(env->img.img, \
	&env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
<<<<<<< HEAD:srcs/execution/refresh_img.c
	if (env->data.game_over == FALSE)
	{
		raycasting(env);
		draw_map(env);
		check_which_opp_display(env, env->data.data_opp);
		frame_gun(env);
	}
	else
		game_over_screen(env);
	mlx_clear_window(env->windows.mlx, env->windows.win);
	mlx_put_image_to_window(env->windows.mlx, env->windows.win,
		env->img.img, 0, 0);
=======
	if (!env->img.addr)
		handle_mlx_errors(env, 1, env->img);
	mlx_clear_window(env->windows.mlx, env->windows.win);
	raycasting(env);
>>>>>>> a551f3f0def2cba5eaad530f7aa1ffb9ce2972b9:srcs/draw/refresh_img.c
	return (0);
}
