/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:46:04 by gclement          #+#    #+#             */
/*   Updated: 2023/06/21 08:54:18 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_opps_sprite(t_env *env, t_img sprite,
		t_ray ray, float wall_height)
{
	t_vector_2f	pix;
	t_vector_2d	textures;
	t_vector_2f	size;
	char		*dst;

	(void) wall_height;
	textures.x = 0;
	pix.x = ray.collision.x;
	size.x = (92 * 4);
	size.y = (100 * 4);
	while (textures.x < 300)
	{
		textures.y = 0;
		pix.y = (OPP_H / ray.length)/* + ((E_H - wall_height / 2) - wall_height)*/;
		while (textures.y < (sprite.height / 4))
		{
			dst = get_pixel_in_texture(sprite, textures.x * \
				((sprite.width / 5) / size.x), textures.y * ((sprite.height / 14) / size.y));
			if (*(unsigned int *)dst != 0x00b7ff)
				my_mlx_pixel_put(&env->img, pix.x, pix.y, *(unsigned int *)dst);
			pix.y++;
			textures.y++;
		}
		pix.x++;
		textures.x++;
	}
}

void	frame_opps(t_env *env)
{
	t_ray	ray_opp;
	t_ray	ray_wall;
	float	wall_height;

	ray_wall = dda(env->data.p_delta.x, env->data.p_delta.y, env);
	ray_opp = dda(env->data.p_delta.x, env->data.p_delta.y, env, 'O');
	wall_height = D_E * (WALL_H / ray_wall.length);
	if (env->data.map_data.map[ray_opp.map.y][ray_opp.map.x] == 'O')
		draw_opps_sprite(env, env->data.sprites_img[2],
			ray_opp, wall_height);
}
