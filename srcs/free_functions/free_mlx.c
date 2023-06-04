/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:24:55 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/04 19:44:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_windows_struct(t_env *env)
{
	if (env->windows.mlx)
		free(env->windows.mlx);
	free_parsing(&env->data);
}
