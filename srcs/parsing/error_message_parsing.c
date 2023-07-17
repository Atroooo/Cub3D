/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:37:51 by lcompieg          #+#    #+#             */
/*   Updated: 2023/07/17 16:56:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_error_message_exit(t_data *map_info, int s, char *str)
{
	if (s == 0)
		printf("Error malloc.\n");
	if (s == 1)
		printf("Error\nMissing color value.\n");
	if (str)
		free(str);
	free_parsing(map_info);
}

void	verif_param(t_data *data)
{
	if (data->no == NULL || data->so == NULL || data->we == NULL || \
		data->ea == NULL)
	{
		printf("Error\nMissing texture ?\n");
		free_parsing(data);
	}
	if (data->floor_color == NULL || data->ceiling_color == NULL)
	{
		printf("Error\nMissing color ?\n");
		free_parsing(data);
	}
}
