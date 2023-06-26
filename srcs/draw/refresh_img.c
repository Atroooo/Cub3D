/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:06:07 by gclement          #+#    #+#             */
/*   Updated: 2023/06/26 14:42:02 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	mlx_clear_window(env->windows.mlx, env->windows.win);
	raycasting(env);
	return (0);
}
