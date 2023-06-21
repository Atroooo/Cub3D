/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:46:04 by gclement          #+#    #+#             */
/*   Updated: 2023/06/21 12:35:32 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*choose_sprite_in_img(t_img sprite, t_vector_2f size, t_vector_2d textures)
{
	char	*dst;

	dst = get_pixel_in_texture(sprite, textures.x * \
				((sprite.width / 5) / size.x), textures.y * ((sprite.height / 20) / (size.y)));
	return (dst);
}

static void	draw_opps_sprite(t_env *env, t_img sprite,
		t_ray ray, float wall_height, int x)
{
	t_vector_2f	pix;
	t_vector_2d	textures;
	t_vector_2f	size;
	char		*dst;

	(void) wall_height;
	textures.x = 0;
	pix.x = x;
	size.x = (92 * 4);
	size.y = (OPP_H / ray.length);
	while (pix.x > 0 && textures.x < 300)
	{
		textures.y = 0;
		pix.y = E_H - (size.y / 2);
		while (pix.y < E_H + size.y / 2)
		{
			dst = choose_sprite_in_img(sprite, size, textures);
			if (*(unsigned int *)dst != 0x00b7ff)
				my_mlx_pixel_put(&env->img, pix.x, pix.y, *(unsigned int *)dst);
			pix.y++;
			textures.y++;
		}
		pix.x++;
		textures.x++;
	}
}

void	frame_opps(t_env *env, t_data data, float x)
{
	float	wall_height;

	(void) x;
	wall_height = D_E * (WALL_H / data.ray_wall.length);
	//printf("ray_opp = %f\n", data.ray_opp->length);
	draw_opps_sprite(env, data.sprites_img[2],
		data.ray_opp, wall_height, x);
}
