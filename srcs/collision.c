/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:40:23 by gclement          #+#    #+#             */
/*   Updated: 2023/06/05 10:51:51 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	collision(int pos_x, int pos_y, char **map)
{
	int	x;
	int	y;

	x = (pos_x + 5) / TILE_SIZE;
	y = (pos_y + 5) / TILE_SIZE;
	if (map[y][x] == '1')
		return (0);
	return (1);
}
