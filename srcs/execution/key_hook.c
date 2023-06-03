/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:27:49 by gclement          #+#    #+#             */
/*   Updated: 2023/06/02 16:46:59 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_close(t_env *env)
{
	if (env->windows.mlx && env->img.img)
		mlx_destroy_image(env->windows.mlx, env->img.img);
	if (env->windows.mlx && env->windows.win)
		mlx_destroy_window(env->windows.mlx, env->windows.win);
	if (env->windows.mlx)
	{
		mlx_destroy_display(env->windows.mlx);
		free_windows_struct(env);
	}
	exit(0);
    return (0);
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == Key_Escape)
		mlx_close(env);
	if (keycode == Key_W || keycode == Key_A
		|| keycode == Key_D || keycode == Key_S)
		move(env, &env->data, keycode);
	return (0);
}
