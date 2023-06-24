/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:46:04 by gclement          #+#    #+#             */
/*   Updated: 2023/06/24 12:01:11 by gclement         ###   ########.fr       */
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

	t_x = textures.x * ((opp.pos.x + 80) / (size.x * opp.mult.x));
	if (t_x < opp.pos.x)
		t_x += opp.pos.x;
	else if (t_x > opp.pos.x + 80)
		t_x -= opp.pos.x;
	height = opp.sprite.height - ((opp.sprite.height - 80) - opp.pos.y);
	t_y = textures.y * (height / (size.y * opp.mult.y));
	if (t_y < opp.pos.y)
		t_y += opp.pos.y + 80;
	else if (t_y > height)
		t_y -= opp.pos.y;
	dst = get_pixel_in_texture(opp.sprite, t_x, t_y);
	return (dst);
}

void	draw_opps_sprite(t_env *env, t_opps opp)
{
	t_vector_2f	pix;
	t_vector_2d	textures;
	t_vector_2f	size;
	char		*dst;

	textures.x = 0;
	pix.x = opp.x;
	size.x = OPP_W / opp.ray.length;
	size.y = (OPP_H / opp.ray.length);
	while (pix.x > 0 && textures.x < size.x)
	{
		textures.y = 0;
		pix.y = E_H - (size.y / 2);
		while (pix.y < E_H + size.y / 2)
		{
			dst = choose_sprite_in_img(size, textures, opp.sprite_data);
			if (*(unsigned int *)dst != 0x00b7ff)
				my_mlx_pixel_put(&env->img, pix.x, pix.y, *(unsigned int *)dst);
			pix.y++;
			textures.y++;
		}
		pix.x++;
		textures.x++;
	}
}

static void	set_sprite_opp(t_opps *opp)
{
	if (opp->frame > 15 && opp->frame < 30)
	{
		opp->sprite_data.pos.y = 95;
		opp->sprite_data.mult.y = 2;
	}
	else if (opp->frame > 30 && opp->frame < 45)
	{
		opp->sprite_data.pos.y = 270;
		opp->sprite_data.mult.y = 4;
	}
	else
	{
		opp->sprite_data.pos.y = 0;
		opp->sprite_data.mult.y = 1;
	}
}

void	frame_opps(t_env *env, t_opps *opp)
{
	printf("opp->x = %f\n", opp->x);
	opp->sprite_data.pos.x = 0;
	opp->sprite_data.mult.x = 1;
	if (opp->frame_hit == 0 && opp->pv > 0)
		set_sprite_opp(opp);
	else if (opp->pv > 0)
	{
		opp->sprite_data.pos.y = 700;
		opp->sprite_data.mult.y = 11;
		opp->frame_hit++;
	}
	if (opp->pv <= 0)
	{
		opp->sprite_data.pos.y = 700;
		opp->sprite_data.mult.y = 14;
		opp->sprite_data.mult.x = 5;
		opp->sprite_data.pos.x = opp->sprite_data.sprite.width - 80;
	}
	if (opp->frame == 60)
		opp->frame = 0;
	if (opp->frame_hit == 5)
		opp->frame_hit = 0;
	draw_opps_sprite(env, *opp);
}
