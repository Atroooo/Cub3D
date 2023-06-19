/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:29:35 by gclement          #+#    #+#             */
/*   Updated: 2023/06/19 15:25:53 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_img	create_textures_img(char *path, t_windows *win, t_env *env)
{
	t_img	data;
	int		fd;
	int		img_width;
	int		img_height;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("textures");
		free_windows_struct(env);
	}
	else
		close(fd);
	data.img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	data.addr = mlx_get_data_addr(\
		data.img, &data.bits_per_pixel, \
		&data.line_length, &data.endian);
	return (data);
}

void	create_all_textures_img(t_env *env)
{
	env->data.textures_img[0] = create_textures_img(\
		env->data.no, &env->windows, env);
	env->data.textures_img[1] = create_textures_img(\
		env->data.ea, &env->windows, env);
	env->data.textures_img[2] = create_textures_img(\
		env->data.so, &env->windows, env);
	env->data.textures_img[3] = create_textures_img(\
		env->data.we, &env->windows, env);
}
