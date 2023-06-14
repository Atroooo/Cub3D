/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:40:23 by gclement          #+#    #+#             */
/*   Updated: 2023/06/14 18:15:33 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	no_collision(float x, float y, t_data *data)
{
	if (distance_wall(x, y, data) <= 1.5)
		return (0);
	return (1);
}

static int	so_collision(float x, float y, t_data *data)
{
	if (distance_wall(x, y, data) <= 1.5)
		return (0);
	return (1);
}

static int	we_collision(float x, float y, t_data *data)
{
	if (distance_wall(x, y, data) <= 1.5)
		return (0);
	return (1);
}

static int	ea_collision(float x, float y, t_data *data)
{

	if (distance_wall(x, y, data) <= 1.5)
		return (0);
	return (1);
}

int	collision(float x, float y, t_data *data, char c)
{
	printf("data->p_angle = %f\n", data->p_angle);
	printf("distance : %f\n", distance_wall(x, y, data));
	if (c == 'N')
		return (no_collision(x, y, data));
	if (c == 'S')
		return (so_collision(x, y, data));
	if (c == 'E')
		return (ea_collision(x, y, data));
	if (c == 'W')
		return (we_collision(x, y, data));
	return (0);
}
