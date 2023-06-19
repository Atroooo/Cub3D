/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:17:39 by gclement          #+#    #+#             */
/*   Updated: 2023/06/19 16:49:08 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_collision(t_env *env, int s)
{
	if (s == 0)
		return (collision(env->data.p_delta.x, env->data.p_delta.y, env, 'N'));
	if (s == 1)
		return (collision(env->data.p_delta.x, env->data.p_delta.y, env, 'S'));
	if (s == 2)
		return (collision(cos(env->data.p_angle + M_PI / 2), \
			sin(env->data.p_angle + M_PI / 2), env, 'W'));
	if (s == 3)
		return (collision(cos(env->data.p_angle + M_PI / 2), \
			sin(env->data.p_angle + M_PI / 2), env, 'E'));
	return (0);
}

int	collision(float pos_x, float pos_y, t_env *env, char c)
{
	t_ray		ray1;
	t_ray		ray2;
	t_ray		ray3;

	if (c == 'S')
	{
		pos_x = -pos_x;
		pos_y = -pos_y;
	}
	ray1 = dda(pos_x, pos_y, env);
	ray2 = dda(pos_x - cos(env->data.p_angle + M_PI / 4), \
		pos_y - sin(env->data.p_angle + M_PI / 4), env);
	ray3 = dda(pos_x + cos(env->data.p_angle + M_PI / 4), \
		pos_y + sin(env->data.p_angle + M_PI / 4), env);
	if (c == 'W' || c == 'E')
	{
		if (ray1.length < 0.30 || ray2.length < 0.30 || ray3.length < 0.30)
			return (0);
		return (1);
	}
	if (ray1.length < 0.20 || ray2.length < 0.20 || ray3.length < 0.20)
		return (0);
	return (1);
}

void	move(t_env *env, t_data *data, int keycode)
{
	if (env->data.is_pressed == 0)
		return ;
	if (keycode == Key_W && check_collision(env, 0))
	{
		data->p_pos_x += data->p_delta.x * 5.0;
		data->p_pos_y += data->p_delta.y * 5.0;
	}
	if (keycode == Key_S && check_collision(env, 1))
	{
		data->p_pos_x -= data->p_delta.x * 5.0;
		data->p_pos_y -= data->p_delta.y * 5.0;
	}
	if (keycode == Key_A && check_collision(env, 2))
	{
		data->p_pos_x -= cos(data->p_angle + M_PI / 2);
		data->p_pos_y -= sin(data->p_angle + M_PI / 2);
	}
	if (keycode == Key_D && check_collision(env, 3))
	{
		data->p_pos_x += cos(data->p_angle + M_PI / 2);
		data->p_pos_y += sin(data->p_angle + M_PI / 2);
	}
	data->p_pos_index.x = data->p_pos_x / TILE_SIZE;
	data->p_pos_index.y = data->p_pos_y / TILE_SIZE;
	refresh_img(env);
}

void	rotate(t_env *env, t_data *data, int keycode)
{
	if (env->data.is_pressed == 0)
		return ;
	if (keycode == Key_Left)
	{
		data->p_angle -= 0.1;
		if (data->p_angle <= 0)
			data->p_angle += 2.0 * M_PI;
	}
	if (keycode == Key_Right)
	{
		data->p_angle += 0.1;
		if (data->p_angle > 2.0 * M_PI)
			data->p_angle -= 2.0 * M_PI;
	}
	data->p_delta.x = cos(data->p_angle);
	data->p_delta.y = sin(data->p_angle);
	refresh_img(env);
}
