/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:06:07 by gclement          #+#    #+#             */
/*   Updated: 2023/06/27 18:38:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_which_opp_display(t_env *env, t_opps *opps)
{
	int	i;

	i = -1;
	while (++i < env->data.opp_nb)
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
				if ((opps[i].frame == 15 || opps[i].frame == 0)
					&& opps[i].pv > 0)
					opps[i].len_sou += 0.2;
				if (opps[i].pv <= 0 && opps[i].frame == 40)
					env->data.map_data.map \
						[opps[i].index.y][opps[i].index.x] = '0';
			}
		}
	}
}

static void	handle_mlx_errors(t_env *env, int s, t_img img)
{
	int	i;

	i = 0;
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
}

int	refresh_img(t_env *env)
{
	mlx_destroy_image(env->windows.mlx, env->img.img);
	env->img.img = mlx_new_image(env->windows.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!env->img.img)
		handle_mlx_errors(env, 0, env->img);
	env->img.addr = mlx_get_data_addr(env->img.img, \
	&env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
	if (!env->img.addr)
		handle_mlx_errors(env, 1, env->img);
	if (env->data.game_over == FALSE)
	{
		raycasting(env);
		check_which_opp_display(env, env->data.data_opp);
		draw_map(env);
		frame_gun(env);
	}
	else
		game_over_screen(env);
	mlx_clear_window(env->windows.mlx, env->windows.win);
	mlx_put_image_to_window(env->windows.mlx, env->windows.win,
		env->img.img, 0, 0);
	return (0);
}
