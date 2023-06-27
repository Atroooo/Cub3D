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

void	set_len_and_col(t_ray *ray, t_env *env, float d_x, float d_y)
{
	if (ray->side == EAST || ray->side == WEST)
	{
		ray->length = ray->side_dist.x - ray->delta_dist.x;
		ray->collision.x = (((env->data.p_pos_y / TILE_SIZE) \
			- ((int)env->data.p_pos_y / TILE_SIZE)) + ray->length * d_y);
	}
	else
	{
		ray->length = ray->side_dist.y - ray->delta_dist.y;
		ray->collision.x = (((env->data.p_pos_x / TILE_SIZE) \
			- ((int)env->data.p_pos_x / TILE_SIZE)) + ray->length * d_x);
	}
	if (env->data.map_data.map[ray->map.y][ray->map.x] == 'O')
		set_ray_opp(*ray, &env->data);
	else
		env->data.ray_wall = *ray;
	if (env->data.map_data.map[ray->map.y][ray->map.x] == 'D')
		set_door(ray, FALSE);
}

static int	is_true(t_ray *ray, t_env *env)
{
	if ((ray->map.y > 0 && ray->map.y < env->data.map_data.map_height) && \
		env->data.map_data.map[ray->map.y][ray->map.x] && \
		env->data.map_data.map[ray->map.y][ray->map.x] != '1' &&
		env->data.map_data.map[ray->map.y][ray->map.x] != 'D')
		return (1);
	return (0);
}

static void	incr_ray_x(t_ray *ray)
{
	ray->side_dist.x += ray->delta_dist.x;
	ray->map.x += ray->step.x;
}

static void	incr_ray_y(t_ray *ray)
{
	ray->side_dist.y += ray->delta_dist.y;
	ray->map.y += ray->step.y;
}

void	dda(float d_x, float d_y, t_env *env, t_ray *ray)
{
	init_ray(ray, &env->data, d_x, d_y);
	while (is_true(ray, env))
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			incr_ray_x(ray);
			if (ray->step.x == 1)
				ray->side = EAST;
			else
				ray->side = WEST;
		}
		else
		{
			incr_ray_y(ray);
			if (ray->step.y == 1)
				ray->side = SOUTH;
			else
				ray->side = NORTH;
		}
		if (env->data.map_data.map[ray->map.y][ray->map.x] == 'O')
			set_len_and_col(ray, env, d_x, d_y);
		if (env->data.map_data.map[ray->map.y][ray->map.x] == 'I')
			set_door(ray, TRUE);
	}
	set_len_and_col(ray, env, d_x, d_y);
}
