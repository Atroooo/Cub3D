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

void	get_delta_dist(t_vector_2d *delta_dist, float dx, float dy)
{
	delta_dist->x = sqrt(1 + (dy * dy) / (dx * dx));
	delta_dist->y = sqrt(1 + (dx * dx) / (dy * dy));
}

int	get_stepX(t_env *env, float dx, t_vector_2d *side_dist, t_vector_2d *delta_dist)
{
	if (dx < 0)
	{
		side_dist->x = (env->data.p_pos_x - env->data.p_pos_x) * delta_dist->x;
		return (-1);
	}
	else
	{
		side_dist->x = (env->data.p_pos_x + 1.0 - env->data.p_pos_x) * delta_dist->x;
		return (1);
	}
	return (0);
}

int	get_stepY(t_env *env, float dy, t_vector_2d *side_dist, t_vector_2d *delta_dist)
{
	if (dy < 0)
	{
		side_dist->y = (env->data.p_pos_y - env->data.p_pos_y) * delta_dist->y;
		return (-1);
	}
	else
	{
		side_dist->y = (env->data.p_pos_y + 1.0 - env->data.p_pos_y) * delta_dist->y;
		return (1);
	}
	return (0);
}

float	dda(float dx, float dy, t_env *env)
{
	float	dist;
	int		x;
	int		y;
	t_vector_2d delta_dist;
	t_vector_2d step;
	t_vector_2d side_dist;
	t_vector_2d wall_coord;

    get_delta_dist(&delta_dist, dx, dy);
	step.x = get_stepX(env, dx, &side_dist, &delta_dist);
	step.y = get_stepY(env, dy, &side_dist, &delta_dist);
	y = (env->data.p_pos_y) / TILE_SIZE;
	x = (env->data.p_pos_x) / TILE_SIZE;
	wall_coord.x = env->data.p_pos_x;
	wall_coord.y = env->data.p_pos_y;
	while (env->data.map_data.map[y][x] != '1')
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			x += step.x;
			wall_coord.x += x * TILE_SIZE;
			// printf("COND1 x = %d y = %d\n", x, y);
		}
		else
		{
			side_dist.y += delta_dist.y;
			y += step.y;
			wall_coord.y += y * TILE_SIZE;
			// printf("COND2 x = %d y = %d\n", x, y);
		}
	}
	env->data.wall_x = wall_coord.x;
	env->data.wall_y = wall_coord.y;
	dist = sqrt((env->data.wall_x - env->data.p_pos_x) * (env->data.wall_x - env->data.p_pos_x) \
	+ (env->data.wall_y - env->data.p_pos_y) * (env->data.wall_y - env->data.p_pos_y));
	printf("DDA x: %f, y: %f %d %d\n", env->data.wall_x, env->data.wall_y, x, y);
	printf("DDA DIST %f\n", dist / 50);
	return (dist / 50);
}