/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:40:23 by gclement          #+#    #+#             */
/*   Updated: 2023/06/13 23:26:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	no_collision(float x, float y, t_data *data)
{
	if (check_cond_angle_no(data))
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

static int	so_collision(float x, float y, t_data *data)
{
	int	return_value;

	return_value = check_cond_angle_so(data);
	if (return_value == 0)
	{
		if (distance_wall(x, y, data) <= 2.5)
			return (0);
	}
	if (return_value == 1)
	{
		if (distance_wall(x, y, data) <= 3.0)
			return (0);
	}
	if (return_value == 2)
	{
		if (distance_wall(x, y, data) <= 1.5)
			return (0);
	}
	else
	{
		if (distance_wall(x, y, data) <= 1.0)
			return (0);
	}
	return (1);
}

static int	we_collision(float x, float y, t_data *data)
{
	if (check_cond_angle_we(data))
	{
		if (distance_wall(x, y, data) <= 2.5)
			return (0);
	}
	else
	{
		if (distance_wall(x, y, data) <= 1.0)
			return (0);
	}
	return (1);
}

static int	ea_collision(float x, float y, t_data *data)
{
	if (check_cond_angle_ea(data))
	{
		if (distance_wall(x, y, data) <= 2.0)
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
