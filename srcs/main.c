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

void	check_params(char *map_path)
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

int	main(int argc, char **argv)
{
	t_map_info	map_info;

	if (argc != 2)
	{
		printf("Usage : ./cub3D <map.cub>\n");
		exit(0);
	}
	check_params(argv[1]);
	parse_map(argv[1], &map_info);
	print_param(&map_info);
	return (0);
}
