/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:17:39 by gclement          #+#    #+#             */
/*   Updated: 2023/06/05 16:34:48 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move(t_env *env, t_data *data, int keycode)
{
	if (keycode == Key_W && collision(\
		data->p_pos_x + data->p_delta_x, \
		data->p_pos_y + data->p_delta_y, data->map_data.map))
	{
		data->p_pos_y += data->p_delta_y;
		data->p_pos_x += data->p_delta_x;
	}
	if (keycode == Key_S && collision(\
		data->p_pos_x - data->p_delta_x, \
		data->p_pos_y - data->p_delta_y, data->map_data.map))
	{
		data->p_pos_y -= data->p_delta_y;
		data->p_pos_x -= data->p_delta_x;
	}
	if (keycode == Key_A && collision(\
		data->p_pos_x - data->p_delta_x, \
		data->p_pos_y + data->p_delta_y, data->map_data.map))
	{
		data->p_pos_y += data->p_delta_y;
		data->p_pos_x -= data->p_delta_x;
	}
	if (keycode == Key_D && collision(\
		data->p_pos_x + data->p_delta_x, \
		data->p_pos_y - data->p_delta_y, data->map_data.map))
	{
		data->p_pos_x += data->p_delta_x;
		data->p_pos_y -= data->p_delta_y;
	}
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
