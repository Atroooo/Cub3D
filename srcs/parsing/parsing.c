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

#include "../../includes/cub3D.h"

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

static int	parse_line(char *line, t_data *map_info)
{
	if (check_line(line) == 0)
		return (0);
	if (get_resolution(line, map_info))
		return (1);
	else if (get_texture(line, map_info))
		return (1);
	else if (get_color(line, map_info))
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

void	parse_map(char *map_path, t_data *map_info)
{
	int		count;
	int		fd;
	char	*line;

	fd = open_map(map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		print_error(1);
	map_info->map_data = malloc(sizeof(t_map_info *));
	if (!map_info->map_data)
		print_error(2);
	count = 0;
	while (line != NULL)
	{
		if (count == 7)
			get_map(line, map_info);
		else
			if (parse_line(line, map_info))
				count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	setup_map(map_info);
}
