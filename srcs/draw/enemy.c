/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:46:04 by gclement          #+#    #+#             */
/*   Updated: 2023/06/21 17:52:17 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*choose_sprite_in_img(t_img sprite, t_vector_2f size, t_vector_2d textures, t_vector_2d pos)
{
	char	*dst;
	int		t_x;
	int		t_y;
	int		height;

	(void) pos;
	(void) height;
	t_x = fmodf(textures.x, size.x);
	height = pos.y + 65;
	// sprite.height * (160 - 80) / sprite.length
	t_y =  textures.y * ((sprite.height / 10) / size.y);
	//printf("pos.y = %d height = %d, t_y = %d\n", 160, (pos.y + 80), t_y);
	dst = get_pixel_in_texture(sprite, t_x, t_y);
	return (dst);
}

static void	draw_opps_sprite(t_env *env, t_img sprite,
		t_ray ray, t_vector_2d pos_in_sprite)
{
	t_vector_2f	pix;
	t_vector_2d	textures;
	t_vector_2f	size;
	char		*dst;

	textures.x = 0;
	pix.x = pos_in_sprite.x;
	size.x = sprite.width / 5.50;
	size.y = (OPP_H / ray.length);
	while (pix.x > 0 && textures.x < size.x)
	{
		textures.y = pos_in_sprite.y;
		pix.y = E_H - (size.y / 2);
		while (pix.y < E_H + size.y / 2)
		{
			dst = choose_sprite_in_img(sprite, size, textures, pos_in_sprite);
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
	t_vector_2d	pos_in_sprite;

	env->data.opp_frame++;
	pos_in_sprite.x = x;
	// if (env->data.opp_frame < 20)
	// 	pos_in_sprite.y = 0;
	// else if (env->data.opp_frame < 40)
	pos_in_sprite.y = 80;
	// else
	// 	pos_in_sprite.y = 160;
	// if (env->data.opp_frame == 60)
	// 	env->data.opp_frame = 0;
	//printf("ray_opp = %f\n", data.ray_opp->length);
	draw_opps_sprite(env, data.sprites_img[2],
		data.ray_opp, pos_in_sprite);
}
