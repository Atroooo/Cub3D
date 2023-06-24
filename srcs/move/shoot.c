/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:36:22 by gclement          #+#    #+#             */
/*   Updated: 2023/06/24 11:52:16 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	shoot(t_env	*env)
{
	t_ray		ray;
	int			i;

	dda(env->data.p_delta.x, env->data.p_delta.y, env, &ray);
	i = search_opp(env->data.ray_opp.map.y, env->data.ray_opp.map.x, env->data);
	if (i == -1)
		return ;
	if (env->data.data_opp[i].frame_hit == 0)
	{
		env->data.data_opp[i].frame_hit = 1;
		env->data.data_opp[i].pv -= 50;
	}
}
