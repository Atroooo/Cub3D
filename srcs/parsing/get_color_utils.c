/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:38:45 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 18:38:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_color_value(t_data *data, char c, char *line)
{
	if (c == 'C')
		if ((data->ceiling_color[0] >= 0 && data->ceiling_color[0] < 255) && \
		(data->ceiling_color[1] >= 0 && data->ceiling_color[1] < 255) && \
		(data->ceiling_color[2] >= 0 && data->ceiling_color[2] < 255))
			return ;
	if (c == 'F')
		if ((data->floor_color[0] >= 0 && data->floor_color[0] < 255) && \
		(data->floor_color[1] >= 0 && data->floor_color[1] < 255) && \
		(data->floor_color[2] >= 0 && data->floor_color[2] < 255))
			return ;
	if (line)
		free(line);
	printf("Error\nWrong color value.\n");
	free_parsing(data);
}

int	check_line_correct(char *str)
{
	char	*tmp;
	int		i;

	if (str == NULL)
		return (0);
	tmp = ft_strtrim(str, "\n ");
	if (!tmp)
		return (0);
	i = 0;
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i]))
		{
			free(tmp);
			return (0);
		}
		i++;
	}
	free(tmp);
	return (1);
}
