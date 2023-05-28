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
	int i;

	printf("R : %d %d\n", data->resX, data->resY);
	printf("NO : %s\n", data->NO);
	printf("SO : %s\n", data->SO);
	printf("WE : %s\n", data->WE);
	printf("EA : %s\n", data->EA);
	printf("Color floor : %d %d %d\n", data->floor_color[0], \
		data->floor_color[1], data->floor_color[2]);
	printf("Color ceiling : %d %d %d\n", data->ceiling_color[0], \
		data->ceiling_color[1], data->ceiling_color[2]);
	printf("player pos : %d %d\n", data->PposX, 
		data->PposY);
	// printf("base map : %s\n", data->map_data->base_map);
	i = 0;
	while (data->map_data->map[i])
	{
		printf("map line %d : %s\n", i, data->map_data->map[i]);
		i++;
	}
}
