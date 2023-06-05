/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:17:39 by gclement          #+#    #+#             */
/*   Updated: 2023/06/05 18:16:36 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_collision(t_data *data, int s)
{
	if (s == 0)
		return (collision(\
		data->p_pos_x + data->p_delta_x, \
		data->p_pos_y + data->p_delta_y, data->map_data.map));
	if (s == 1)
		return (collision(\
		data->p_pos_x + data->p_delta_x, \
		data->p_pos_y - data->p_delta_y, data->map_data.map));
	if (s == 2)
		return (collision(\
		data->p_pos_x + data->p_delta_x - M_PI * 1.5, \
		data->p_pos_y - data->p_delta_y - M_PI * 1.5, data->map_data.map));
	if (s == 3)
		return (collision(\
		data->p_pos_x + data->p_delta_x + M_PI * 1.5, \
		data->p_pos_y + data->p_delta_y + M_PI * 1.5, data->map_data.map));
	return (0);
}

void	move(t_env *env, t_data *data, int keycode)
{
	if (keycode == Key_W && check_collision(data, 0))
	{
		data->p_pos_y += data->p_delta_y;
		data->p_pos_x += data->p_delta_x;
	}
	if (keycode == Key_S && check_collision(data, 1))
	{
		data->p_pos_y -= data->p_delta_y;
		data->p_pos_x -= data->p_delta_x;
	}
	if (keycode == Key_A && check_collision(data, 2))
	{
		if (data->p_delta_y < 0)
		{
			data->p_pos_x = data->p_pos_x + data->p_delta_x - M_PI * 1.5;
			data->p_pos_y = data->p_pos_y - data->p_delta_y - M_PI * 1.5;
		}
	}
	if (keycode == Key_D && check_collision(data, 3))
	{
		if (data->p_delta_y < 0 || data->p_delta_x < 0)
		{
			data->p_pos_x = data->p_pos_x + data->p_delta_x + M_PI * 1.5;
			data->p_pos_y = data->p_pos_y + data->p_delta_y + M_PI * 1.5;
		}
	}
	printf("KEY %d x: %f, y: %f delta x %f delta y %f\n", keycode, data->p_pos_x, data->p_pos_y, data->p_delta_x, data->p_delta_y);
	refresh_img(env);
}

void	rotate(t_env *env, t_data *data, int keycode)
{
	if (keycode == Key_Left)
	{
		data->p_angle -= 0.1;
		if (data->p_angle <= 0)
			data->p_angle += 2 * M_PI;
		data->p_delta_x = cos(data->p_angle) * 5;
		data->p_delta_y = sin(data->p_angle) * 5;
	}
	if (keycode == Key_Right)
	{
		data->p_angle += 0.1;
		if (data->p_angle > 2 * M_PI)
			data->p_angle -= 2 * M_PI;
		data->p_delta_x = cos(data->p_angle) * 5;
		data->p_delta_y = sin(data->p_angle) * 5;
	}
	refresh_img(env);
}
