/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:15:44 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 23:15:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_color_value(t_data *data, char c, char *line)
{
	if (c == 'C')
		if ((data->ceiling_color[0] > 0 && data->ceiling_color[0] < 255) && \
		(data->ceiling_color[1] > 0 && data->ceiling_color[1] < 255) && \
		(data->ceiling_color[2] > 0 && data->ceiling_color[2] < 255))
			return ;
	if (c == 'F')
		if ((data->floor_color[0] > 0 && data->floor_color[0] < 255) && \
		(data->floor_color[1] > 0 && data->floor_color[1] < 255) && \
		(data->floor_color[2] > 0 && data->floor_color[2] < 255))
			return ;
	if (line)
		free(line);
	printf("Error\nWrong color value.\n");
	free_parsing(data);
}

static int	check_line_correct(char *str)
{
	char	*tmp;
	int		i;

	if (str == NULL)
		return (0);
	printf("str |%s|\n", str);
	i = 0;
	tmp = ft_strtrim(str, " ");
	if (!tmp)
		return (0);
	while (tmp[i])
	{
		printf("char |%c|\n", tmp[i]);
		if (tmp[i] != '\n' && !ft_isdigit(tmp[i]))
		{
			free(tmp);
			return (0);
		}
		i++;
	}
	free(tmp);
	return (1);
}

static void	get_floor_color(char *line, t_data *data)
{
	char	**split;
	char	**split2;

	split = ft_split(line, ',');
	if (!split)
		print_error_message_exit(data, 0, line);
	split2 = ft_split(split[0], ' ');
	if (!split2 || !split2[1] || !check_line_correct(split[1]) || \
	!check_line_correct(split[2]) || !check_line_correct(split2[1]))
	{
		free_split(split, split2);
		print_error_message_exit(data, 1, line);
	}
	data->floor_color = malloc(sizeof(int) * 3);
	if (data->floor_color == NULL)
		print_error_message_exit(data, 0, line);
	data->floor_color[0] = ft_atoi(split2[1]);
	data->floor_color[1] = ft_atoi(split[1]);
	data->floor_color[2] = ft_atoi(split[2]);
	free_split(split, split2);
	check_color_value(data, 'F', line);
}

static void	get_ceiling_color(char *line, t_data *data)
{
	char	**split;
	char	**split2;

	split = ft_split(line, ',');
	if (!split)
		print_error_message_exit(data, 0, line);
	split2 = ft_split(split[0], ' ');
	if (!split2 || !split2[1] || !check_line_correct(split[1]) || 
	!check_line_correct(split[2]) || !check_line_correct(split2[1]))
	{
		free_split(split, split2);
		print_error_message_exit(data, 1, line);
	}
	data->ceiling_color = malloc(sizeof(int) * 3);
	if (!data->ceiling_color)
		print_error_message_exit(data, 0, line);
	data->ceiling_color[0] = ft_atoi(split2[1]);
	data->ceiling_color[1] = ft_atoi(split[1]);
	data->ceiling_color[2] = ft_atoi(split[2]);
	free_split(split, split2);
	check_color_value(data, 'C', line);
}

int	get_color(char *line, t_data *data)
{
	if (ft_strcompare("F ", line, 2))
	{
		get_floor_color(line, data);
		return (1);
	}
	else if (ft_strcompare("C ", line, 2))
	{
		get_ceiling_color(line, data);
		return (1);
	}
	return (0);
}
