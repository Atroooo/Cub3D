/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:38:51 by gclement          #+#    #+#             */
/*   Updated: 2023/06/26 16:56:44 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_opp(t_env *env, t_opps *opp)
{
	int	y;
	int	x;

	y = opp->index.y;
	x = opp->index.x;
	if (env->data.p_pos_index.x > x && env->data.map_data.map[y][x + 1] != '1')
		opp->index.x++;
	else if (env->data.p_pos_index.x < x
		&& env->data.map_data.map[opp->index.y][x - 1] != '1')
		opp->index.x--;
	if (env->data.p_pos_index.y > y && env->data.map_data.map[y + 1][x] != '1')
		opp->index.y++;
	else if (env->data.p_pos_index.y < y
		&& env->data.map_data.map[y - 1][x] != '1')
		opp->index.y--;
	env->data.map_data.map[opp->index.y][opp->index.x] = 'O';
	env->data.map_data.map[y][x] = '0';
}
