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

typedef struct s_map
{
    char    **map;
    int     map_width;
    int     map_height;
}   t_map;

typedef struct s_map_info
{
    int     res_X;
    int     res_Y;
    char    *NO_texture;
    char    *SO_texture;
    char    *WE_texture;
    char    *EA_texture;
    int     player_pos_X;
    int     player_pos_Y;
    char    player_orientation;
    int     *floor_color;
    int     *ceiling_color;
    t_map   *map;
    
}   t_map_info;

void	parse_map(char *map_path, t_map_info *map_info);
int 	get_resolution(char *line, t_map_info *map_info);
int		get_texture(char *line, t_map_info *map_info);
int		get_color(char *line, t_map_info *map_info);
int    	get_map(char *line, t_map_info *map_info);
int 	ft_strcompare(char *str1, char *str, int n);

#endif