/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:06:51 by gclement          #+#    #+#             */
/*   Updated: 2023/06/26 15:33:33 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*pick_pixel_textures(int y, int x, t_img img)
{
	char			*dst;
	int				t_x;
	int				t_y;

	t_y = fmodf(y, img.height);
	t_x = fmodf(x, img.width);
	dst = get_pixel_in_texture(img, t_x, t_y);
	return (dst);
}

void	game_over_screen(t_env *env)
{
	int		y;
	int		x;
	int		t_x;
	int		t_y;
	char	*dst;

	x = WIN_WIDTH / 6;
	t_x = 0;
	t_y = 0;
	while (x < WIN_WIDTH - (WIN_WIDTH / 6))
	{
		y = WIN_HEIGHT / 6;
		t_y = 0;
		while (y < WIN_HEIGHT - (WIN_HEIGHT / 6))
		{
			dst = pick_pixel_textures(t_y, t_x, env->data.textures_img[5]);
			my_mlx_pixel_put(&env->img, x, y, *(unsigned int *)dst);
			y++;
			t_y++;
		}
		x++;
		t_x++;
	}
}
