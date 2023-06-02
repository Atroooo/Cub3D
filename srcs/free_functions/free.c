/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:24:55 by marvin            #+#    #+#             */
/*   Updated: 2023/05/28 00:24:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_char_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_parsing(t_data *data)
{
	if (data->no != NULL)
		free(data->no);
	if (data->so != NULL)
		free(data->so);
	if (data->we != NULL)
		free(data->we);
	if (data->ea != NULL)
		free(data->ea);
	if (data->floor_color != NULL)
		free(data->floor_color);
	if (data->ceiling_color != NULL)
		free(data->ceiling_color);
	if (data->map_data.base_map != NULL)
		free(data->map_data.base_map);
	if (data->map_data.map != NULL)
		free_char_array(data->map_data.map);
	close(data->fd);
	exit(0);
}

void	free_split(char **split, char **split2)
{
	free_char_array(split);
	free_char_array(split2);
}
