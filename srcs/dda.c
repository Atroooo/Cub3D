/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:03:53 by marvin            #+#    #+#             */
/*   Updated: 2023/06/14 20:03:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	get_delta_dist(t_vector_2f *delta_dist, float dx, float dy)
{
	if (dx == 0.0f)
		delta_dist->x = 1e30;
	else
		delta_dist->x = fabs(1.0f / dx);
	if (dy == 0.0f)
		delta_dist->y = 1e30;
	else
		delta_dist->y = fabs(1.0f / dy);
}

int	get_stepx(t_data *data, float dx, t_vector_2f *side_dist, \
	t_vector_2f *delta_dist)
{
	if (dx < 0)
	{
		side_dist->x = (data->p_pos_x - (int)data->p_pos_x) \
			* (delta_dist->x);
		return (-1);
	}
	else
	{
		side_dist->x = ((int)data->p_pos_x + 1.0f - data->p_pos_x) \
			* (delta_dist->x);
		return (1);
	}
	return (0);
}

int	get_stepy(t_data *data, float dy, t_vector_2f *side_dist, \
	t_vector_2f *delta_dist)
{
	if (dy < 0)
	{
		side_dist->y = (data->p_pos_y - (int)data->p_pos_y) \
			* (delta_dist->y);
		return (-1);
	}
	else
	{
		side_dist->y = ((int)data->p_pos_y + 1.0f - data->p_pos_y) \
			* (delta_dist->y);
		return (1);
	}
	return (0);
}

float	dda(float dx, float dy, t_env *env)
{
	t_vector_2f	side_dist;
	t_vector_2f	delta_dist;
	t_vector_2d	map;
	t_vector_2d	step;
	int			side;
	t_vector_2f p_pos;
	t_vector_2f wall_pos;

    get_delta_dist(&delta_dist, dx, dy);
	step.x = get_stepx(&env->data, dx, &side_dist, &delta_dist);
	step.y = get_stepy(&env->data, dy, &side_dist, &delta_dist);
	p_pos.x = env->data.p_pos_x;
	p_pos.y = env->data.p_pos_y;
	map.y = (env->data.p_pos_y) / TILE_SIZE;
	map.x = (env->data.p_pos_x) / TILE_SIZE;
	while (env->data.map_data.map[map.y][map.x] != '1')
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			map.x += step.x;
			side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			map.y += step.y;
			side = 1;
		}
	}
	// printf("map.x = %d, map.y = %d\n", map.x, map.y);
	wall_pos.x = map.x * TILE_SIZE;
	wall_pos.y = map.y * TILE_SIZE;
	my_mlx_puts_line(&env->img, p_pos, wall_pos, 0xeb3734);
	if (side == 0)
		return (side_dist.x - delta_dist.x);
	else if (side == 1)
		return (side_dist.y - delta_dist.y);
	return (0);
}