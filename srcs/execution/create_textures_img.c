/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:29:35 by gclement          #+#    #+#             */
/*   Updated: 2023/06/08 11:12:15 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	create_textures_img(char *path, t_windows *win)
{
	t_img	data;
	int		fd;
	int		img_width;
	int		img_height;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit (0);
	else
		close(fd);
	data.img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	data.addr = mlx_get_data_addr(\
		data.img, &data.bits_per_pixel, \
		&data.line_length, &data.endian);
	return (data);
}
