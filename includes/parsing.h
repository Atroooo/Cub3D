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

void	parse_map(char *map_path, t_data *map_info);
int		get_resolution(char *line, t_data *map_info);
int		get_texture(char *line, t_data *map_info);
int		get_color(char *line, t_data *map_info);
int		get_map(char *line, t_data *map_info);
int		ft_strcompare(char *str1, char *str, int n);
void	setup_map(t_data *data);

#endif