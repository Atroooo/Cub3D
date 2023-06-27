/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:36:22 by gclement          #+#    #+#             */
/*   Updated: 2023/06/27 19:12:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int    mouse_hook_button(int button, int x, int y, t_env *env)
{
    (void) x;
    (void) y;
    if (button == 1)
        shoot(env);
    return (0);
}

static t_vector_2d	check_shoot(t_env *env, float dy, float dx)
{
	t_vector_2d	index;
	float		pix_x;
	float		pix_y;
	int			i;

	index.y = (env->data.p_pos_y) / TILE_SIZE;
	index.x = (env->data.p_pos_x) / TILE_SIZE;
	pix_x = env->data.p_pos_x + 5.0;
	pix_y = env->data.p_pos_y + 5.0;
	while (env->data.map_data.map[index.y][index.x] != '1')
	{
		pix_y += dy * TILE_SIZE;
		pix_x += dx * TILE_SIZE;
		index.y = pix_y / TILE_SIZE;
		index.x = pix_x / TILE_SIZE;
		i = search_opp(index.y, index.x, env->data);
		if ((env->data.map_data.map[index.y][index.x] == 'O'
			&& i >= 0 && env->data.data_opp[i].pv > 0))
			break ;
	}
	return (index);
}

void	shoot(t_env	*env)
{
	t_vector_2d	index;
	int			i;

	index = check_shoot(env, env->data.p_delta.y, env->data.p_delta.x);
	i = search_opp(index.y, index.x, env->data);
	if (i == -1)
		return ;
	if (env->data.data_opp[i].frame_hit == 0)
	{
		env->data.data_opp[i].frame_hit = 1;
		env->data.data_opp[i].pv -= 34;
		if (env->data.data_opp[i].pv <= 0)
			env->data.data_opp[i].frame = 0;
	}
}
