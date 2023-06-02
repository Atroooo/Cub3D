/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:17:39 by gclement          #+#    #+#             */
/*   Updated: 2023/06/02 13:42:45 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move(t_env *env, int keycode)
{
	if (keycode == Key_W)
		env->data.p_pos_y -= MOVE_SPEED;
	if (keycode == Key_A)
		env->data.p_pos_x -= MOVE_SPEED;	
	if (keycode == Key_D)
		env->data.p_pos_x += MOVE_SPEED;	
	if (keycode == Key_S)
		env->data.p_pos_y += MOVE_SPEED;
	refresh_img(env);
}