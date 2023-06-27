/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:27:49 by gclement          #+#    #+#             */
/*   Updated: 2023/06/27 18:49:04 by marvin           ###   ########.fr       */
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
	free_img(env);
	mlx_mouse_show(env->windows.mlx, env->windows.win);
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
		rotate(&env->data, keycode);
	if (keycode == Key_E)
		open_door(env, &env->data);
	if (keycode == Key_Space)
		env->data.frame = 1;
	return (0);
}

static void	teleport_cursor(t_env *env, int x)
{
	if (x > WIN_WIDTH - 200)
		mlx_mouse_move(env->windows.mlx, env->windows.win, \
			WIN_WIDTH - 300, WIN_HEIGHT / 2);
	else if (x < 200)
		mlx_mouse_move(env->windows.mlx, env->windows.win, \
			300, WIN_HEIGHT / 2);
}

int	mouse_hook(int x, int y, t_env *env)
{
	float	angle_inc;

	(void) y;
	teleport_cursor(env, x);
	angle_inc = 0.003;
	if (x > 0 && x < (WIN_WIDTH / 2 - 600))
	{
		env->data.p_angle -= angle_inc;
		if (env->data.p_angle > 2.0 * M_PI)
			env->data.p_angle -= 5.0 * M_PI;
	}
	else if (x > (WIN_WIDTH / 2 + 600) && x < WIN_WIDTH)
	{
		env->data.p_angle += angle_inc;
		if (env->data.p_angle <= 0)
			env->data.p_angle += 5.0 * M_PI;
	}
	env->data.p_delta.x = cos(env->data.p_angle);
	env->data.p_delta.y = sin(env->data.p_angle);
	return (0);
}
