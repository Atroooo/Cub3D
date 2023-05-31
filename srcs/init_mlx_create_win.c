/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_create_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:17:57 by gclement          #+#    #+#             */
/*   Updated: 2023/05/29 14:58:34 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx_create_win(t_windows *win)
{
	t_img		img;

	win->mlx = mlx_init();
	// if (!win->mlx) !!!!!!!!!! A actualise
	// 	free_and_exit(win);
	win->win = mlx_new_window(win->mlx, 1920, 1080, "cub3d");
	img.img = mlx_new_image(win->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// if (!img.img || !img.addr || !win->win) !!!!!!!!!! A actualise
	// 	free_and_exit(win);
	win->img = img;
	//draw_all_lines(win->img, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
}
