/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:41:28 by gclement          #+#    #+#             */
/*   Updated: 2023/06/21 07:44:15 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector_2f
{
	float	x;
	float	y;
}	t_vector_2f;

typedef struct s_vector_2d
{
	int	x;
	int	y;
}	t_vector_2d;

typedef enum s_side
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_side;

/*Image structure*/
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
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
	t_vector_2f	p_pos_index;
	float		p_angle;
	t_vector_2f	p_delta;
	float		r_perpendicular;
	float		angle;
	float		wall_x;
	float		wall_y;
	int			*floor_color;
	uint32_t	floor_hexa;
	int			*ceiling_color;
	uint32_t	ceiling_hexa;
	t_map_info	map_data;
	t_img		textures_img[4];
	t_img		sprites_img[3];
	int			frame;
}	t_data;

/*Vectors*/

typedef struct s_ray
{
	t_vector_2f	side_dist;
	t_vector_2f	delta_dist;
	t_vector_2d	map;
	t_vector_2d	step;
	t_vector_2f	collision;
	float		length;
	t_side		side;
}	t_ray;

/*Main environnement*/
typedef struct s_env
{
	t_data		data;
	t_img		img;
	t_windows	windows;
}	t_env;
#endif