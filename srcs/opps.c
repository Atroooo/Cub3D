/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:49:54 by gclement          #+#    #+#             */
/*   Updated: 2023/06/26 17:05:53 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_opp(t_opps *opp, t_img sprite, int y, int x)
{
	opp->frame = 0;
	opp->frame_hit = 0;
	opp->pv = 100;
	opp->in_fov = FALSE;
	opp->index.x = x;
	opp->index.y = y;
	opp->sprite_data.sprite = sprite;
	opp->x = -1;
	opp->len_sou = 0;
}

static void	init_all_opps(t_data *data, t_opps *opps_arr)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (data->map_data.map[y])
	{
		x = 0;
		while (data->map_data.map[y][x])
		{
			if (data->map_data.map[y][x] == 'O')
			{
				init_opp(&opps_arr[count], data->sprites_img[2], y, x);
				count++;
			}
			x++;
		}
		y++;
	}
}

int	search_opp(int y, int x, t_data data)
{
	int	i;

	i = 0;
	while (i < data.opp_nb)
	{
		if (data.data_opp[i].index.x == x
			&& data.data_opp[i].index.y == y)
			return (i);
		i++;
	}
	return (-1);
}

void	set_ray_opp(t_ray ray, t_data *data)
{
	int	i;

	i = search_opp(ray.map.y, ray.map.x, *data);
	if (i == -1)
		return ;
	data->data_opp[i].ray = ray;
	data->data_opp[i].in_fov = TRUE;
	data->ray_opp = ray;
	data->ray_opp.active = TRUE;
}

void	malloc_opp_arr(t_data *data)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (data->map_data.map[y])
	{
		x = 0;
		while (data->map_data.map[y][x])
		{
			if (data->map_data.map[y][x] == 'O')
				count++;
			x++;
		}
		y++;
	}
	data->data_opp = malloc(count * sizeof(t_opps));
	if (!data->data_opp)
		free_parsing(data);
	data->opp_nb = count;
	init_all_opps(data, data->data_opp);
}
