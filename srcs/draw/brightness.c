/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:39:10 by gclement          #+#    #+#             */
/*   Updated: 2023/06/28 13:55:43 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	create_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [3]){b, g, r});
}

static unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

static unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

static unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

unsigned int	pixel_brightness(float distance, unsigned int color)
{
	char	r;
	char	g;
	char	b;

	if (distance > 1.10)
	{
		r = get_r(color) / distance + 22;
		g = get_g(color) / distance + 22;
		b = get_b(color) / distance + 22;
		color = create_rgb(r, g, b);
	}
	return (color);
}
