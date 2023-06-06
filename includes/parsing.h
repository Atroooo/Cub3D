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

/*Get parameters*/
void	parse_map(char *map_path, t_data *map_info);
int		ft_strcompare(char *str1, char *str, int n);
char	*setup_line(char *line);
int		get_texture(char *line, t_data *map_info);
void	check_color_value(t_data *data, char c, char *line);
int	    check_line_correct(char *str);
int		get_color(char *line, t_data *map_info);
int		get_map(char *line, t_data *map_info);
void	get_size_map(t_data *data);
void	setup_map(t_data *data);
void	check_map(t_data *data);

/*Error message*/
void	print_error_message_exit(t_data *map_info, int s, char *str);

/*Free Functions*/
void	free_parsing(t_data *data);
void	free_split(char **split, char **split2);

#endif