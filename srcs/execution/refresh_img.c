/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:06:07 by gclement          #+#    #+#             */
/*   Updated: 2023/06/26 13:39:45 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_which_opp_display(t_env *env, t_opps *opps)
{
	int	i;

	i = 0;
	while (i < env->data.opp_nb)
	{
		if (opps[i].in_fov == TRUE)
		{
			//printf("opp.width = %d, index;x = %d, index.y = %d\n", opps[i].sprite_data.sprite.width, opps[i].index.x, opps[i].index.y);
			frame_opps(env, &opps[i]);
			opps[i].in_fov = FALSE;
			opps[i].frame++;
			opps[i].x = -1;
			env->data.ray_opp.active = FALSE;
		}
		i++;
	}
}

int	refresh_img(t_env *env)
{
	mlx_destroy_image(env->windows.mlx, env->img.img);
	env->img.img = mlx_new_image(env->windows.mlx, WIN_WIDTH, WIN_HEIGHT);
	env->img.addr = mlx_get_data_addr(env->img.img, \
	&env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
	mlx_clear_window(env->windows.mlx, env->windows.win);
	raycasting(env);
	draw_map(env);
	check_which_opp_display(env, env->data.data_opp);
	frame_gun(env);
	mlx_put_image_to_window(env->windows.mlx, env->windows.win,
		env->img.img, 0, 0);
	return (0);
}
