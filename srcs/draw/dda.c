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

#include "cub3D.h"

void	set_len_and_col(t_ray *ray, t_data data, float d_x, float d_y)
{
	if (ray->side == EAST || ray->side == WEST)
	{
		ray->length = ray->side_dist.x - ray->delta_dist.x;
		ray->collision.x = (((data.p_pos_y / TILE_SIZE) \
			- ((int)data.p_pos_y / TILE_SIZE)) + ray->length * d_y);
	}
	else
	{
		ray->length = ray->side_dist.y - ray->delta_dist.y;
		ray->collision.x = (((data.p_pos_x / TILE_SIZE) \
			- ((int)data.p_pos_x / TILE_SIZE)) + ray->length * d_x);
	}
}

static int	is_true(t_ray ray, t_env *env)
{
	if ((ray.map.y > 0 && ray.map.y < env->data.map_data.map_height) && \
		env->data.map_data.map[ray.map.y][ray.map.x] && \
		env->data.map_data.map[ray.map.y][ray.map.x] != '1')
		return (1);
	return (0);
}

t_ray	dda(float d_x, float d_y, t_env *env)
{
	t_ray		ray;

	init_ray(&ray, env, d_x, d_y);
	while (is_true(ray, env))
	{
		if (ray.side_dist.x < ray.side_dist.y)
		{
			ray.side_dist.x += ray.delta_dist.x;
			ray.map.x += ray.step.x;
			if (ray.step.x == 1)
				ray.side = EAST;
			else
				ray.side = WEST;
		}
		else
		{
			ray.side_dist.y += ray.delta_dist.y;
			ray.map.y += ray.step.y;
			if (ray.step.y == 1)
				ray.side = SOUTH;
			else
				ray.side = NORTH;
		}
	}
	return (set_len_and_col(&ray, env->data, d_x, d_y), ray);
}
