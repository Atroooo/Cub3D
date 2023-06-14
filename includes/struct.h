/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:41:28 by gclement          #+#    #+#             */
/*   Updated: 2023/06/14 20:00:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*Image structure*/
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

/*MLX structure*/
typedef struct s_windows
{
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_windows;

/* Data */
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
	float		p_pos_x;
	float		p_pos_y;
	char		player_orientation;
	float		p_angle;
	float		p_delta_x;
	float		p_delta_y;
	float		r_perpendicular;
	float		angle;
	float		wall_x;
	float		wall_y;
	int			*floor_color;
	uint32_t	floor_hexa;
	int			*ceiling_color;
	uint32_t	ceiling_hexa;
	t_map_info	map_data;
	t_img		textures_img[5];
}	t_data;

/*Vectors*/
typedef struct s_vector_2d
{
	float	x;
	float	y;
}	t_vector_2d;

/*Main environnement*/
typedef struct s_env
{
	t_data		data;
	t_img		img;
	t_windows	windows;
}	t_env;
#endif