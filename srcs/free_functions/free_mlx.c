/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclement <gclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:24:55 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/26 18:23:37 by gclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_windows_struct(t_env *env)
{
	if (env->windows.mlx)
		free(env->windows.mlx);
	if (env->data.data_opp)
		free(env->data.data_opp);
	free_parsing(&env->data);
}
