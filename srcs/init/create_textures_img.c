/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:29:35 by gclement          #+#    #+#             */
/*   Updated: 2023/06/27 13:22:38 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	handle_mlx_errors(t_env *env, int s, t_img img)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (env->data.textures_img[i].img != NULL)
			mlx_destroy_image(env->windows.mlx, \
				env->data.textures_img[i].img);
		i++;
	}
	if (s == 1)
		mlx_destroy_image(env->windows.mlx, img.img);
	mlx_destroy_window(env->windows.mlx, env->windows.win);
	mlx_destroy_display(env->windows.mlx);
	free(env->windows.mlx);
	free_parsing(&env->data);
}

static void	handle_wrong_texture(t_env *env, int i)
{
	int	index_texture;

	index_texture = 0;
	while (index_texture < i - 1 && index_texture < 6)
	{
		mlx_destroy_image(env->windows.mlx, \
				env->data.textures_img[index_texture].img);
		index_texture++;
	}
	if (i > 6)
	{
		index_texture = 0;
		while (index_texture < i - 6)
		{
			mlx_destroy_image(env->windows.mlx, \
				env->data.textures_img[index_texture].img);
			index_texture++;
		}
	}
	mlx_destroy_image(env->windows.mlx, env->img.img);
	mlx_destroy_window(env->windows.mlx, env->windows.win);
	mlx_destroy_display(env->windows.mlx);
	free_windows_struct(env);
}

static t_img	create_textures_img(char *path, \
	t_windows *win, t_env *env, int i)
{
	t_img	data;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("textures");
		handle_wrong_texture(env, i);
	}
	else
		close(fd);
	data.img = mlx_xpm_file_to_image(win->mlx, path, &data.width, &data.height);
	if (!data.img)
		handle_mlx_errors(env, 0, data);
	data.addr = mlx_get_data_addr(\
		data.img, &data.bits_per_pixel, \
		&data.line_length, &data.endian);
	if (!data.addr)
		handle_mlx_errors(env, 1, data);
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
	env->data.textures_img[4] = create_textures_img(\
		"./textures/door.xpm", &env->windows, env, 5);
	env->data.textures_img[5] = create_textures_img(\
		"./textures/game_over.xpm", &env->windows, env, 6);
	env->data.sprites_img[0] = create_textures_img(\
		"./textures/pompe.xpm", &env->windows, env, 7);
	env->data.sprites_img[1] = create_textures_img(\
		"./textures/pompe_shoot.xpm", &env->windows, env, 8);
	env->data.sprites_img[2] = create_textures_img(\
		"./textures/alien_spritesheet.xpm", &env->windows, env, 9);
}
