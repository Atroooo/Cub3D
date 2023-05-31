/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:00:22 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 22:00:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	check_params(char *map_path)
{
	if (!map_path)
	{
		printf("Error.\n");
		exit(0);
	}
	if (ft_strcmp(ft_strrchr(map_path, '.'), ".cub") != 0)
	{
		printf("Check your extension.\n");
		exit(0);
	}
}

static void	init_value(t_data *data)
{
	data->fd = 0;
	data->res_x = 0;
	data->res_y = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->p_pos_x = 0;
	data->p_pos_y = 0;
	data->player_orientation = 0;
	data->floor_color = NULL;
	data->ceiling_color = NULL;
	data->map_data = NULL;
}

int	main(int argc, char **argv)
{
	t_data		map_info;
	// t_windows	win;

	if (argc != 2)
	{
		printf("Usage : ./cub3D <map.cub>\n");
		exit(0);
	}
	check_params(argv[1]);
	init_value(&map_info);
	parse_map(argv[1], &map_info);
	print_param(&map_info);
	free_parsing(&map_info);
	// init_mlx_create_win(&win);
	// mlx_loop(win.mlx);
	return (0);
}
