/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:09:10 by marvin            #+#    #+#             */
/*   Updated: 2023/05/28 00:09:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_strcompare(char *str1, char *str2, int n)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}
