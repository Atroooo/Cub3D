/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:45:49 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 21:45:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_linux/mlx.h"
# include "../libft/header/libft.h"
# include "keys.h"
# include "parsing.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

void	free_char_array(char **array);
void	print_param(t_data *map_info);

#endif