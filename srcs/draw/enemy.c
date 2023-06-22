/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:46:04 by gclement          #+#    #+#             */
/*   Updated: 2023/06/22 17:03:23 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//height = sprite.height - 1325; (1 img);

//(dp.screen.x - dp.draw_start.x)
				// * dp.sprite.width / dp.width;
	
static char	*choose_sprite_in_img(t_vector_2f size,
	t_vector_2d textures, t_sprite opp)
{
	char	*dst;
	int		t_x;
	int		t_y;
	int		height;

	t_x = textures.x * ((size.x) / (size.y + opp.ray.length));
	height = opp.sprite.height - ((opp.sprite.height - 80) - opp.pos.y);
	t_y = textures.y * (height / (size.y * opp.mult));
	if (t_y < opp.pos.y)
		t_y += opp.pos.y + 80;
	else if (t_y > height)
		t_y -= opp.pos.y;
	// printf("pos.y = %d height = %d, t_y = %d\n", opp.pos.y, height, t_y);
	dst = get_pixel_in_texture(opp.sprite, t_x, t_y);
	return (dst);
}

static void	draw_opps_sprite(t_env *env, t_sprite opp)
{
	t_vector_2f	pix;
	t_vector_2d	textures;
	t_vector_2f	size;
	char		*dst;

	textures.x = 0;
	pix.x = opp.pos.x;
	//printf("pix.x = %f\n", pix.x);
	size.x = (opp.sprite.width / 5);
	size.y = (OPP_H / opp.ray.length);
	while (pix.x > 0 && textures.x < (size.x))
	{
		textures.y = 0;
		pix.y = E_H - (size.y / 2);
		while (pix.y < E_H + size.y / 2)
		{
			dst = choose_sprite_in_img(size, textures, opp);
			if (*(unsigned int *)dst != 0x00b7ff)
				my_mlx_pixel_put(&env->img, pix.x, pix.y, *(unsigned int *)dst);
			pix.y++;
			textures.y++;
		}
		pix.x++;
		textures.x++;
	}
}

void	frame_opps(t_env *env, t_sprite *opp)
{
	//printf("x = %d\n", opp->pos.x);
	if (opp->frame < 15)
	{
		opp->pos.y = 0;
		opp->mult = 1;
	}
	else if (opp->frame < 30)
	{
		opp->pos.y = 95;
		opp->mult = 2;
	}
	else
	{
		opp->pos.y = 0;
		opp->mult = 1;
	}
	if (opp->frame == 30)
		opp->frame = 0;
	draw_opps_sprite(env, *opp);
}
