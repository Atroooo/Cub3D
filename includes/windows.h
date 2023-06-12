/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:19:39 by gclement          #+#    #+#             */
/*   Updated: 2023/06/12 11:05:38 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOWS_H
# define WINDOWS_H

# include "cub3D.h"

void	init_mlx_create_win(t_env *env);
t_img	refresh_img(t_env *env);
t_img	create_textures_img(char *path, t_windows *win);
void	create_all_textures_img(t_env *env);

#endif