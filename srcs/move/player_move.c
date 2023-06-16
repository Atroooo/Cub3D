/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:17:39 by gclement          #+#    #+#             */
/*   Updated: 2023/06/15 23:22:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_collision(t_data *data, int s)
{
	if (s == 0)
		return (collision(data->p_pos_x + data->p_delta_x, \
		data->p_pos_y + data->p_delta_y, data, 'N'));
	if (s == 1)
		return (collision(data->p_pos_x + data->p_delta_x, \
		data->p_pos_y - data->p_delta_y, data, 'S'));
	if (s == 2)
		return (collision(data->p_pos_x - cos(data->p_angle + M_PI / 2), \
		data->p_pos_y - sin(data->p_angle + M_PI / 2), data, 'W'));
	if (s == 3)
		return (collision(data->p_pos_x + cos(data->p_angle + M_PI / 2), \
		data->p_pos_y + sin(data->p_angle + M_PI / 2), data, 'E'));
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
		data->p_pos_x -= cos(data->p_angle + M_PI / 2);
		data->p_pos_y -= sin(data->p_angle + M_PI / 2);
	}
	if (keycode == Key_D && check_collision(data, 3))
	{
		data->p_pos_x += cos(data->p_angle + M_PI / 2);
		data->p_pos_y += sin(data->p_angle + M_PI / 2);
	}
	refresh_img(env);
}

void	rotate(t_env *env, t_data *data, int keycode)
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
	data->p_delta_x = cos(data->p_angle);
	data->p_delta_y = sin(data->p_angle);
	refresh_img(env);
}
