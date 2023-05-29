/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:55:16 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 21:55:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_map_info
{
	char	**map;
	int		map_width;
	int		map_height;
	char	*base_map;
}	t_map_info;

typedef struct s_data
{
	int			resX;
	int 		resY;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	int 		PposX;
	int 		PposY;
	char		player_orientation;
	int 		*floor_color;
	int			*ceiling_color;
    t_map_info	*map_data;
}	t_data;

void	parse_map(char *map_path, t_data *map_info);
int		get_resolution(char *line, t_data *map_info);
int		get_texture(char *line, t_data *map_info);
int		get_color(char *line, t_data *map_info);
int		get_map(char *line, t_data *map_info);
int		ft_strcompare(char *str1, char *str, int n);
void	setup_map(t_data *data);

#endif