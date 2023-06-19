/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:52:59 by lcompieg          #+#    #+#             */
/*   Updated: 2023/06/19 15:03:53 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYHOOK_FUNCTIONS_H
# define KEYHOOK_FUNCTIONS_H

int		key_hook(int keycode, t_env *env);
int		key_hook_unpressed(int keycode, t_env *env);
int		mouse_hook(int button, int x, int y, t_env *env);
int		mlx_close(t_env *env);

#endif