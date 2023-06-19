/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:44:59 by marvin            #+#    #+#             */
/*   Updated: 2023/06/19 23:44:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_stepx(t_data *data, float dx, t_ray *ray)
{
	float	pos_in_tile;

	pos_in_tile = (data->p_pos_x / TILE_SIZE);
	if (dx < 0)
	{
		ray->side_dist.x = (pos_in_tile - (int)pos_in_tile) \
			* (ray->delta_dist.x);
		ray->side = WEST;
		return (-1);
	}
	else
	{
		ray->side_dist.x = ((int)pos_in_tile + 1.0f - pos_in_tile) \
			* (ray->delta_dist.x);
		ray->side = EAST;
		return (1);
	}
	return (0);
}

static int	get_stepy(t_data *data, float dy, t_ray *ray)
{
	float	pos_in_tile;

	pos_in_tile = (data->p_pos_y / TILE_SIZE);
	if (dy < 0)
	{
		ray->side_dist.y = (pos_in_tile - (int)pos_in_tile) \
			* (ray->delta_dist.y);
		ray->side = SOUTH;
		return (-1);
	}
	else
	{
		ray->side_dist.y = ((int)pos_in_tile + 1.0f - pos_in_tile) \
			* (ray->delta_dist.y);
		ray->side = NORTH;
		return (1);
	}
	return (0);
}

void	init_ray(t_ray *ray, t_env *env, float d_x, float d_y)
{
	ray->delta_dist.x = fabs(1.0f / d_x);
	ray->delta_dist.y = fabs(1.0f / d_y);
	ray->step.x = get_stepx(&env->data, d_x, ray);
	ray->step.y = get_stepy(&env->data, d_y, ray);
	ray->map.y = (env->data.p_pos_y) / TILE_SIZE;
	ray->map.x = (env->data.p_pos_x) / TILE_SIZE;
	ray->length = 0.0f;
}
