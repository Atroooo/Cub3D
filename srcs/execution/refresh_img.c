/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:06:07 by gclement          #+#    #+#             */
/*   Updated: 2023/06/22 14:32:06 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	refresh_img(t_env *env)
{
	mlx_destroy_image(env->windows.mlx, env->img.img);
	env->img.img = mlx_new_image(env->windows.mlx, WIN_WIDTH, WIN_HEIGHT);
	env->img.addr = mlx_get_data_addr(env->img.img, \
	&env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
	mlx_clear_window(env->windows.mlx, env->windows.win);
	raycasting(env);
	draw_map(env);
	// if (env->data.opp.ray.exist == TRUE)
	// {
	// 	frame_opps(env, &env->data.opp);
	// 	env->data.opp.ray.exist = FALSE;
	// 	env->data.opp.pos.x = 0;
	// }
	frame_gun(env);
	env->data.opp.frame++;
	// mlx_put_image_to_window(env->windows.mlx, env->windows.win,
	// 	env->img.img, 0, 0);
	return (0);
}
