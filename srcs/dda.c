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
	delta_dist->x = fabs(1.0f / dx);
	delta_dist->y = fabs(1.0f / dy);
}

int	get_stepx(t_data *data, float dx, t_vector_2f *side_dist, \
	t_vector_2f *delta_dist)
{
	float	pos_in_tile;

	pos_in_tile = (data->p_pos_x / TILE_SIZE);
	if (dx < 0)
	{
		side_dist->x = (pos_in_tile - (int)pos_in_tile) \
			* (delta_dist->x);
		return (-1);
	}
	else
	{
		side_dist->x = ((int)pos_in_tile + 1.0f - pos_in_tile) \
			* (delta_dist->x);
		return (1);
	}
	return (0);
}

int	get_stepy(t_data *data, float dy, t_vector_2f *side_dist, \
	t_vector_2f *delta_dist)
{
	float	pos_in_tile;

	pos_in_tile = (data->p_pos_y / TILE_SIZE);
	if (dy < 0)
	{
		side_dist->y = (pos_in_tile - (int)pos_in_tile) \
			* (delta_dist->y);
		return (-1);
	}
	else
	{
		side_dist->y = ((int)pos_in_tile + 1.0f - pos_in_tile) \
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

	get_delta_dist(&delta_dist, dx, dy);
	step.x = get_stepx(&env->data, dx, &side_dist, &delta_dist);
	step.y = get_stepy(&env->data, dy, &side_dist, &delta_dist);
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
	if (side == 0)
		return (side_dist.x - delta_dist.x);
	else if (side == 1)
		return (side_dist.y - delta_dist.y);
	return (0);
}
