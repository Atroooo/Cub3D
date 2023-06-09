/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:27:49 by gclement          #+#    #+#             */
/*   Updated: 2023/06/24 13:36:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_hook_unpressed(int keycode, t_env *env)
{
	(void) keycode;
	env->data.is_pressed = 0;
	return (0);
}

int	mlx_close(t_env *env)
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
	if (env->windows.mlx && env->img.img)
		mlx_destroy_image(env->windows.mlx, env->img.img);
	if (env->windows.mlx && env->windows.win)
		mlx_destroy_window(env->windows.mlx, env->windows.win);
	if (env->windows.mlx)
	{
		mlx_destroy_display(env->windows.mlx);
		free_windows_struct(env);
	}
	free_parsing(&env->data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_env *env)
{
	env->data.is_pressed = 1;
	if (keycode == Key_Escape)
		mlx_close(env);
	if (keycode == Key_W || keycode == Key_S \
	|| keycode == Key_A || keycode == Key_D)
		move(env, &env->data, keycode);
	if (keycode == Key_Left || keycode == Key_Right)
		rotate(env, &env->data, keycode);
	return (0);
}
