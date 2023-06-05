/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:17:39 by gclement          #+#    #+#             */
/*   Updated: 2023/06/05 10:57:35 by gclement         ###   ########.fr       */
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
	refresh_img(env);
}

void	rotate(t_env *env, t_data *data, int keycode)
{
	if (keycode == Key_A)
	{
		data->p_angle -= 0.1;
		if (data->p_angle <= 0)
			data->p_angle += 2 * M_PI;
		data->p_delta_x = cos(data->p_angle) * 5;
		data->p_delta_y = sin(data->p_angle) * 5;
	}
	if (keycode == Key_D)
	{
		data->p_angle += 0.1;
		if (data->p_angle > 2 * M_PI)
			data->p_angle -= 2 * M_PI;
		data->p_delta_x = cos(data->p_angle) * 5;
		data->p_delta_y = sin(data->p_angle) * 5;
	}
	refresh_img(env);
}
