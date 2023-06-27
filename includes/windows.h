/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:19:39 by gclement          #+#    #+#             */
/*   Updated: 2023/06/27 18:19:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOWS_H
# define WINDOWS_H

# include "cub3D.h"

void	init_mlx_create_win(t_env *env);
int		refresh_img(t_env *env);
void	create_all_textures_img(t_env *env);

#endif