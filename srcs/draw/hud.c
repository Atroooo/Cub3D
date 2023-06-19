
#include "cub3D.h"

void gun(t_env *env, t_img sprite)
{
	float	y;
	float	x;
	int		t_y;
	int		t_x;
	char	*dst;

	x = WIN_WIDTH / 3;
	t_x = 0;
	while (x < WIN_WIDTH / 2)
	{
		t_y = 0;
		y = WIN_HEIGHT / 3;
		t_x = fmodf(x, sprite.width) * sprite.width / 2;
		while (y < WIN_HEIGHT)
		{
			//printf("%f * (%d / %d) = %f\n", y ,sprite.height, (WIN_HEIGHT / 6),  y * (sprite.height / 5));
			t_y = fmodf(y, sprite.height)  * sprite.height / 2;
			dst = get_pixel_in_texture(sprite, t_x, t_y);
			//printf("t_y = %d, t_x = %d, dst = %d\n", t_y, t_x, *(unsigned int *)dst);
			if (*(unsigned int *)dst != 0xffffff)
				my_mlx_pixel_put(&env->img, x, y, *(unsigned int *)dst);
			y++;
			t_y++;
		}
		x++;
		t_x++;
	}
	mlx_put_image_to_window(env->windows.mlx, env->windows.win, env->img.img, 0, 0);	
}