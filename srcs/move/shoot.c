/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:36:22 by gclement          #+#    #+#             */
/*   Updated: 2023/06/24 11:28:58 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	shoot(t_env	*env)
{
	t_ray		ray;

	dda(env->data.p_delta.x, env->data.p_delta.y, env, &ray);
	if (env->data.data_opp.ray.exist == FALSE)
		return ;
	env->data.data_opp.frame_hit = 1;
}
