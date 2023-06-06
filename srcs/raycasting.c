/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:35:38 by gclement          #+#    #+#             */
/*   Updated: 2023/06/06 17:29:40 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//x + 1, y - 1
static	int	check_wall_angle(int x, int y, t_data data, char **map)
{
	int	p_x;
	int	p_y;

	p_y = data.p_pos_y / TILE_SIZE;
	p_x = data.p_pos_x / TILE_SIZE;
	if (p_y > y || p_x < x)
	{
		if (!map[y + 1] || !map[y][x] || !map[y + 1][x] || !map[y][x - 1])
			return (1);
		if (p_y > y && p_x < x && map[y + 1][x] == '1' && map[y][x - 1] == '1')
			return (0);
	}
	else
	{
		if (!map[y][x] || !map[y - 1] || !map[y - 1][x] || !map[y][x + 1])
			return (1);
		if (p_y < y && map[y - 1][x] == '1' && map[y][x + 1] == '1')
			return (0);
	}
	return (1);
}

float	calc_radius(t_env *env, float dy, float dx)
{
	int		y;
	int		x;
	float	pix_x;
	float	pix_y;
	float	distance;

	y = (env->data.p_pos_y) / TILE_SIZE;
	x = (env->data.p_pos_x) / TILE_SIZE;
	pix_x = env->data.p_pos_x + 5;
	pix_y = env->data.p_pos_y + 5;
	while (env->data.map_data.map[y][x] != '1')
	{
		my_mlx_pixel_put(&env->img, pix_x, pix_y, 0x41801f);
		distance += 0.1;
		pix_y += dy / 5;
		pix_x += dx / 5;
		y = pix_y / TILE_SIZE;
		x = pix_x / TILE_SIZE;
		if (!check_wall_angle(x, y, env->data, env->data.map_data.map))
			break ;
	}
	return (distance);
}

void	raycasting(t_env *env)
{
	float	angle;
	float	dy;
	float	dx;
	float	x;

	x = 0;
	angle = env->data.p_angle + (11 * M_PI / 6);
	while (x < WIN_WIDTH)
	{
		dx = cos(angle) * 5;
		dy = sin(angle) * 5;
		env->data.angle = angle;
		x++;
		draw_wall(calc_radius(env, dy, dx), env, x);
		angle += RAD / 40;
	}
}

// fish_eye = distance = rayon devant le joueur * cos(env->data.p_angle);
// recuperer angle pour calcul fisheye, reorganise raycasting, calc_radius