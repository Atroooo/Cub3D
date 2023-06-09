/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:40:23 by gclement          #+#    #+#             */
/*   Updated: 2023/06/09 15:00:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int    no_collision(float x, float y, t_data *data)
{
    if (check_cond_angle(1, data))
	{
		if (distance_wall(x, y, data) <= 1.0)
			return (0);		
	}
	else
	{
		if (distance_wall(x, y, data) <= 0.0)
			return (0);
	}
	return (1);
}

static int    so_collision(float x, float y, t_data *data)
{
    if (check_cond_angle(2, data))
	{
		if (distance_wall(x, y, data) <= 2.0)
			return (0);
	}
	else
	{
		if (distance_wall(x, y, data) <= 0.75)
			return (0);
	}
	return (1);
}

static int    we_collision(float x, float y, t_data *data)
{
	if (check_cond_angle(3, data))
	{
		if (distance_wall(x, y, data) <= 3.0)
			return (0);
	}
	else
	{
		if (distance_wall(x, y, data) <= 1.0)
			return (0);
	}
	return (1);
}

static int    ea_collision(float x, float y, t_data *data)
{
	if (check_cond_angle(4, data))
	{
		if (distance_wall(x, y, data) <= 1.0)
			return (0);
	}
	else
	{
		if (distance_wall(x, y, data) <= 0.5)
			return (0);
	}
	return (1);
}

int	collision(float x, float y, t_data *data, char c)
{
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
