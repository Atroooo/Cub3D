/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:29:35 by gclement          #+#    #+#             */
/*   Updated: 2023/06/07 16:53:09 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	create_textures_img(char *path, t_windows *win)
{
	t_img	data;
	int		img_width;
	int		img_height;

	if (open(path, O_RDONLY) < 0)
		exit (0);
	data.img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	printf("img_height = %d", img_height);
	return (data);
}
