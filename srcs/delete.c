/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:38:39 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 23:38:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	print_param(t_data *data)
{
	int	i;

	printf("NO : %s\n", data->no);
	printf("SO : %s\n", data->so);
	printf("WE : %s\n", data->we);
	printf("EA : %s\n", data->ea);
	printf("Color floor : %d %d %d\n", data->floor_color[0], \
		data->floor_color[1], data->floor_color[2]);
	printf("Color ceiling : %d %d %d\n", data->ceiling_color[0], \
		data->ceiling_color[1], data->ceiling_color[2]);
	printf("player pos : x %f y %f\n", data->p_pos_x,
		data->p_pos_y);
	// printf("base map : %s\n", data->map_data.base_map);
	i = 0;
	while (data->map_data.map[i])
	{
		printf("map line %d : %s\n", i, data->map_data.map[i]);
		i++;
	}
	printf("map_width = %d\n map_height = %d\n", data->map_data.map_width, data->map_data.map_height);
}

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

 void	my_mlx_puts_line(t_img *data, t_vector_2f p1, t_vector_2f p2, uint32_t color)
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
			my_mlx_pixel_put(data, p1.x, p1.y, color);
		p1.x += x_inc;
		p1.y += y_inc;
		steps--;
	}
}