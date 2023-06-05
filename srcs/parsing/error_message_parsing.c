/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:37:51 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/05 19:22:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_error_message_exit(t_data *map_info, int s, char *str)
{
	if (s == 0)
		printf("Error malloc.\n");
	if (s == 1)
	{
		printf("Error\nMissing color value.\n");
		free(map_info->floor_color);
		free(map_info->ceiling_color);
	}
	if (str)
		free(str);
	free_parsing(map_info);
}
