/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:17:39 by gclement          #+#    #+#             */
/*   Updated: 2023/06/24 14:20:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

# define HITBOX	0.3

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

	if (c == 'S' || c == 'W')
	{
		pos_x = -pos_x;
		pos_y = -pos_y;
	}
	dda(pos_x, pos_y, env, &ray1);
	dda(pos_x - cos(env->data.p_angle + M_PI / 4), \
		pos_y - sin(env->data.p_angle + M_PI / 4), env, &ray2);
	dda(pos_x + cos(env->data.p_angle + M_PI / 4), \
		pos_y + sin(env->data.p_angle + M_PI / 4), env, &ray3);
	if (c == 'W' || c == 'E')
	{
		if (ray1.length < HITBOX || ray2.length < HITBOX || ray3.length < HITBOX)
			return (0);
		return (1);
	}
	if (ray1.length < HITBOX - 0.1 || ray2.length < HITBOX - 0.1 || ray3.length < HITBOX - 0.1)
		return (0);
	return (1);
}

void	move(t_env *env, t_data *data, int keycode)
{
	(void) env;
	if (keycode == Key_W && check_collision(env, 0))
	{
		data->p_pos_x += data->p_delta.x * 3.0;
		data->p_pos_y += data->p_delta.y * 3.0;
	}
	if (keycode == Key_S && check_collision(env, 1))
	{
		data->p_pos_x -= data->p_delta.x * 3.0;
		data->p_pos_y -= data->p_delta.y * 3.0;
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
}

void	rotate(t_data *data, int keycode)
{
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
}
