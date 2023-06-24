/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:36:27 by gclement          #+#    #+#             */
/*   Updated: 2023/06/24 10:36:56 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h" 

void	set_door(t_ray *ray, t_bools is_open)
{
	ray->door.is_meet = TRUE;
	ray->door.is_open = is_open;
	if (ray->side == EAST || ray->side == WEST)
		ray->door.length = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->door.length = ray->side_dist.y - ray->delta_dist.y;
	ray->door.index.y = ray->map.y;
	ray->door.index.x = ray->map.x;
}

void	open_door(t_env *env, t_data *data)
{
	t_ray	ray;

	dda(data->p_delta.x, data->p_delta.y, env, &ray);
	if (ray.door.is_meet == TRUE && ray.door.is_open == TRUE)
		data->map_data.map[ray.door.index.y][ray.door.index.x] = 'D';
	else if (ray.door.is_meet == TRUE && ray.door.is_open == FALSE)
		data->map_data.map[ray.door.index.y][ray.door.index.x] = 'I';
}