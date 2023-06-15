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
		side_dist->x = (env->data.p_pos_x - (int)env->data.p_pos_x) * delta_dist->x;
		return (-1);
	}
	else
	{
		side_dist->x = ((int)env->data.p_pos_x + 1.0 - env->data.p_pos_x) * delta_dist->x;
		return (1);
	}
	return (0);
}

int	get_stepY(t_env *env, float dy, t_vector_2d *side_dist, t_vector_2d *delta_dist)
{
	if (dy < 0)
	{
		side_dist->y = (env->data.p_pos_y - (int)env->data.p_pos_y) * delta_dist->y;
		return (-1);
	}
	else
	{
		side_dist->y = ((int)env->data.p_pos_y + 1.0 - env->data.p_pos_y) * delta_dist->y;
		return (1);
	}
	return (0);
}

static void	invers_point(t_vector_2d *p1, t_vector_2d *p2)
{
	t_vector_2d	tmp;

	if (p2->y < p1->y)
	{
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
}

 void	my_mlx_puts_line(t_img *data, t_vector_2d p1, t_vector_2d p2)
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
			my_mlx_pixel_put(data, p1.x, p1.y, 0xeb3734);
		p1.x += x_inc;
		p1.y += y_inc;
		steps--;
	}
}

float	dda(float dx, float dy, t_env *env)
{
	float	dist;
	int		x;
	int		y;
	t_vector_2d delta_dist;
	t_vector_2d step;
	t_vector_2d side_dist;
	t_vector_2d p_pos;

    get_delta_dist(&delta_dist, dx, dy);
	step.x = get_stepX(env, dx, &side_dist, &delta_dist);
	step.y = get_stepY(env, dy, &side_dist, &delta_dist);
	// printf("step.x = %f, step.y = %f\n", step.x, step.y);
	p_pos.x = env->data.p_pos_x;
	p_pos.y = env->data.p_pos_y;
	y = (env->data.p_pos_y) / TILE_SIZE;
	x = (env->data.p_pos_x) / TILE_SIZE;
	while (env->data.map_data.map[y][x] != '1')
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			x += step.x;
			printf("COND1 delta_dist.x; = %f, side_dist.x = %f side_dist.y = %f x = %d y = %d\n", delta_dist.x, side_dist.x, side_dist.y, x, y);
		}
		else
		{
			side_dist.y += delta_dist.y;
			y += step.y;
			printf("COND2 delta_dist.y = %f, side_dist.x = %f side_dist.y = %f x = %d y = %d\n", delta_dist.y, side_dist.x, side_dist.y, x, y);
		}
		//my_mlx_pixel_put(&env->img, side_dist.x, side_dist.y, );
	}
	my_mlx_puts_line(&env->img, p_pos, side_dist);
	env->data.wall_x = side_dist.x;
	env->data.wall_y = side_dist.y;
	dist = sqrt((env->data.wall_x - env->data.p_pos_x) * (env->data.wall_x - env->data.p_pos_x) \
	+ (env->data.wall_y - env->data.p_pos_y) * (env->data.wall_y - env->data.p_pos_y));
	printf("DDA x: %f, y: %f %d %d\n", env->data.wall_x, env->data.wall_y, x, y);
	printf("DDA DIST %f\n", dist / 50);
	return (dist / 50);
}