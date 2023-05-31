/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:26:37 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 22:26:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	print_error(int s)
{
	if (s == 0)
		printf("Error opening file.\n");
	if (s == 1)
		printf("Error reading file.\n");
	if (s == 2)
		printf("Malloc error\n");
	exit(0);
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isalpha(line[i]) || ft_isdigit(line[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	parse_line(char *line, t_data *data)
{
	if (check_line(line) == 0)
		return (0);
	if (get_resolution(line, data))
		return (1);
	else if (get_texture(line, data))
		return (1);
	else if (get_color(line, data))
		return (1);
	return (0);
}

static int	open_map(char *map_path, int flags)
{
	int	fd;

	fd = open(map_path, flags);
	if (fd == -1)
		print_error(0);
	return (fd);
}

void	parse_map(char *map_path, t_data *data)
{
	int		count;
	char	*line;

	data->fd = open_map(map_path, O_RDONLY);
	line = get_next_line(data->fd);
	if (!line)
		print_error(1);
	data->map_data = malloc(sizeof(t_map_info));
	if (!data->map_data)
		print_error(2);
	data->map_data->base_map = NULL;
	data->map_data->map = NULL;
	count = 0;
	while (line != NULL)
	{
		if (count == 7)
			get_map(line, data);
		else
			if (parse_line(line, data))
				count++;
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	setup_map(data);
}
