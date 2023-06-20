
#include "cub3D.h"

void gun(t_env *env, t_img sprite)
{
	t_vector_2f	pix;
	t_vector_2d	textures;
	t_vector_2f	size;
	char		*dst;

	textures.x = 0;
	textures.y = 0;
	pix.x = WIN_WIDTH / 3;
	textures.x = 0;
	size.x = (WIN_WIDTH / 2);
	size.y = (WIN_WIDTH / 2);
	while (pix.x < WIN_WIDTH / 2)
	{
		textures.y = 0;
		pix.y = WIN_HEIGHT - 500;
		textures.x = pix.x * (sprite.height / size.x);
		while (pix.y < WIN_HEIGHT)
		{
			textures.y = pix.y * (sprite.width / size.y);
			//printf("%f * (%d / %f) = %f\n", pix.y, sprite.height, size.y, pix.y * (sprite.height / size.y));
			dst = get_pixel_in_texture(sprite, textures.x, textures.y);
			//printf("t_y = %d, t_x = %d\n", textures.y, textures.x);
			if (*(unsigned int *)dst != 0xffffff)
				my_mlx_pixel_put(&env->img, pix.x, pix.y, *(unsigned int *)dst);
			pix.y++;
			textures.y++;
		}
		pix.x++;
		textures.x++;
	}
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, env->img.img, 0, 0);	
}