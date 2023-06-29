/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:29:35 by gclement          #+#    #+#             */
/*   Updated: 2023/06/29 17:38:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	handle_wrong_texture(t_env *env, int i)
{
	int	index_texture;

	index_texture = 0;
	while (index_texture < i - 1)
	{
		mlx_destroy_image(env->windows.mlx, \
				env->data.textures_img[index_texture].img);
		index_texture++;
	}
	mlx_destroy_image(env->windows.mlx, env->img.img);
	mlx_destroy_window(env->windows.mlx, env->windows.win);
	mlx_destroy_display(env->windows.mlx);
	free_windows_struct(env);
}

static void	check_file_extension(char *path, t_env *env, int i)
{
	if (ft_strcmp(ft_strrchr(path + 1, '.'), ".xpm") != 0)
	{
		printf("Error\nWrong texture extension.\n");
		handle_wrong_texture(env, i);
	}
}

static t_img	create_textures_img(char *path, \
	t_windows *win, t_env *env, int i)
{
	t_img	data;
	int		fd;

	check_file_extension(path, env, i);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		perror("textures");
		handle_wrong_texture(env, i);
	}
	else
		close(fd);
	data.img = mlx_xpm_file_to_image(win->mlx, path, &data.width, &data.height);
	if (!data.img)
		handle_wrong_texture(env, i);
	data.addr = mlx_get_data_addr(\
		data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	if (!data.addr)
	{
		mlx_destroy_image(env->windows.mlx, data.img);
		handle_wrong_texture(env, i);
	}
	return (data);
}

void	create_all_textures_img(t_env *env)
{
	env->data.textures_img[0] = create_textures_img(\
		env->data.no, &env->windows, env, 1);
	env->data.textures_img[1] = create_textures_img(\
		env->data.ea, &env->windows, env, 2);
	env->data.textures_img[2] = create_textures_img(\
		env->data.so, &env->windows, env, 3);
	env->data.textures_img[3] = create_textures_img(\
		env->data.we, &env->windows, env, 4);
}
