/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:24:55 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/01 17:00:57 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_windows_struct(t_env *env)
{
	if (env->windows.mlx)
		free(env->windows.mlx);
	if (env->windows.win)
		free(env->windows.win);
}
