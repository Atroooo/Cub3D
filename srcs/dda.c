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

int	get_stepx(t_data *data, float dx, t_ray *ray)
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

int	get_stepy(t_data *data, float dy, t_ray *ray)
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

void	init_ray(t_ray *ray, t_data *data, float d_x, float d_y)
{
	ray->delta_dist.x = fabs(1.0f / d_x);
	ray->delta_dist.y = fabs(1.0f / d_y);
	ray->step.x = get_stepx(data, d_x, ray);
	ray->step.y = get_stepy(data, d_y, ray);
	ray->map.y = (data->p_pos_y) / TILE_SIZE;
	ray->map.x = (data->p_pos_x) / TILE_SIZE;
}

void	set_len_and_col(t_ray *ray, t_data *data, float d_x, float d_y)
{
	if (ray->side == EAST || ray->side == WEST)
	{
		ray->length = ray->side_dist.x - ray->delta_dist.x;
		ray->collision.x = (((data->p_pos_y / TILE_SIZE) \
			- ((int)data->p_pos_y / TILE_SIZE)) + ray->length * d_y);
	}
	else
	{
		ray->length = ray->side_dist.y - ray->delta_dist.y;
		ray->collision.x = (((data->p_pos_x / TILE_SIZE) \
			- ((int)data->p_pos_x / TILE_SIZE)) + ray->length * d_x);
	}
	if (data->map_data.map[ray->map.y][ray->map.x] != 'O')
		data->ray_opp = *ray;
	else
		data->ray_wall = *ray;
}

void	dda(float d_x, float d_y, t_data *data, t_ray *ray)
{
	init_ray(ray, data, d_x, d_y);
	while (data->map_data.map[ray->map.y][ray->map.x] != '1')
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			if (ray->step.x == 1)
				ray->side = EAST;
			else
				ray->side = WEST;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			if (ray->step.y == 1)
				ray->side = SOUTH;
			else
				ray->side = NORTH;
		}
		if (data->map_data.map[ray->map.y][ray->map.x] != 'O')
			set_len_and_col(ray, data, d_x, d_y);
	}
	set_len_and_col(ray, data, d_x, d_y);
}
