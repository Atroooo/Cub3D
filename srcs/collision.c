/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:40:23 by gclement          #+#    #+#             */
/*   Updated: 2023/06/08 13:58:32 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

//Reflechir a une solution pour les distances bas et droite : le "pixel" du 1 est plus loin que les 2 autres murs
static float	distance_wall(float x, float y, t_data *data)
{
	float	dist;
	int		x_t;
	int		y_t;

	dist = 0.0;
	x_t = x / TILE_SIZE;
	y_t = y / TILE_SIZE;
	while (y_t > 0 && y_t < data->map_data.map_height && \
	data->map_data.map[y_t][x_t] && data->map_data.map[y_t][x_t] != '1')
	{
		x += (x - data->p_pos_x);
		y += (y - data->p_pos_y);
		x_t = x / TILE_SIZE;
		y_t = y / TILE_SIZE;
		dist += 0.05;
	}
	// if (y_t == data->map_data.map_height - 1)
	// 	return (dist / 3.0); //Solution ok pour une map carre mais pas pour une map avec forme speciale
	return (dist);
}

int	collision(int x, int y, t_data *data, char c)
{
	float	dist;

	dist = distance_wall(x, y, data);
	printf("dist = %f\n", dist);
	if (c == 'N')
		if (dist <= 0.05)
			return (0);
	if (c == 'S')
		if (dist <= 0.05)
			return (0);
	if (c == 'W')
		if (dist <= 0.05)
			return (0);
	if (c == 'E')
		if (dist <= 0.05)
			return (0);
	return (1);
}
