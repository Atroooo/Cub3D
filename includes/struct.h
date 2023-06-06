/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:41:28 by gclement          #+#    #+#             */
/*   Updated: 2023/06/03 07:47:24 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


/* PARSING */

typedef struct s_map_info
{
	char	**map;
	int		map_width;
	int		map_height;
	char	*base_map;
}	t_map_info;

typedef struct s_data
{
	int			fd;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			p_pos_x;
	int			p_pos_y;
	char		player_orientation;
	float		p_angle;
	float		p_delta_x;
	float		p_delta_y;
	float		r_perpendicular;
	float		angle;
	int			*floor_color;
	int			*ceiling_color;
	t_map_info	map_data;
}	t_data;

/* MLX */

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_windows
{
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_windows;

typedef struct s_env
{
	t_data		data;
	t_img		img;
	t_windows	windows;
}	t_env;

#endif