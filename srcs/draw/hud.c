
#include "cub3D.h"

static void	draw_gun(t_env *env, t_img sprite, float y)
{
	t_vector_2f	pix;
	t_vector_2d	textures;
	t_vector_2f	size;
	char		*dst;

	textures.x = 0;
	pix.x = WIN_WIDTH / 3;
	size.x = (WIN_WIDTH / 3);
	size.y = (WIN_HEIGHT / 2);
	while (pix.x < WIN_WIDTH - 650)
	{
		textures.y = 0;
		pix.y = y;
		while (pix.y < WIN_HEIGHT)
		{
			dst = get_pixel_in_texture(sprite, textures.x * (sprite.width / size.x), textures.y * (sprite.height / size.y));
			if (*(unsigned int *)dst != 0x000000)
				my_mlx_pixel_put(&env->img, pix.x, pix.y, *(unsigned int *)dst);
			pix.y++;
			textures.y++;
		}
		pix.x++;
		textures.x++;
	}
}

void	frame_gun(t_env *env)
{
	if (env->data.frame == 0)
		draw_gun(env, env->data.sprites_img[0], WIN_HEIGHT - 400);
	else
	{
		draw_gun(env, env->data.sprites_img[1], WIN_HEIGHT - 510);
		env->data.frame++;
		if (env->data.frame == 5)
			env->data.frame = 0;
	}
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, env->img.img, 0, 0);
}

