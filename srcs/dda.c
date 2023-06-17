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


static void	invers_point(t_vector_2f *p1, t_vector_2f *p2)
{
	t_vector_2f	tmp;

	if (p2->y < p1->y)
	{
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
}

static void	my_mlx_puts_line(t_img *data, t_vector_2f p1, t_vector_2f p2)
{
	float	steps;
	float	d_x;
	float	d_y;
	float	x_inc;
	float	y_inc;

	invers_point(&p1, &p2);
	d_x = p2.x - p1.x;
	d_y = p2.y - p1.y;
	if (d_x > d_y)
		steps = d_x;
	else
		steps = d_y;
	x_inc = d_x / steps;
	y_inc = d_y / steps;
	while (steps >= 0)
	{
		if (p1.x < 1920 && p1.x > 0 && p1.y < 1080 && p1.y > 0)
			my_mlx_pixel_put(data, p1.x, p1.y, 0x46eb34);
		p1.x += x_inc;
		p1.y += y_inc;
		steps--;
	}
}

void	get_delta_dist(t_ray *ray, float dx, float dy)
{
	ray->delta_dist.x = fabs(1.0f / dx);
	ray->delta_dist.y = fabs(1.0f / dy);
}

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

t_ray	dda(float dx, float dy, t_env *env)
{
	t_ray		ray;

	(void)my_mlx_puts_line;
	get_delta_dist(&ray, dx, dy);
	ray.step.x = get_stepx(&env->data, dx, &ray);
	ray.step.y = get_stepy(&env->data, dy, &ray);
	ray.map.y = (env->data.p_pos_y) / TILE_SIZE;
	ray.map.x = (env->data.p_pos_x) / TILE_SIZE;
	while (env->data.map_data.map[ray.map.y][ray.map.x] != '1')
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
	if (ray.side == EAST || ray.side == WEST)
	{
		ray.length = ray.side_dist.x - ray.delta_dist.x;
		ray.collision.x = ((int)env->data.p_pos_y / TILE_SIZE) + ray.length * dy;
	}
	else
	{
		ray.length = ray.side_dist.y - ray.delta_dist.y;
		ray.collision.x = ((int)env->data.p_pos_x / TILE_SIZE) +  ray.length * dx;
	}
	//my_mlx_puts_line(&env->img, p_pos, ray.collision);
	return (ray);
}
