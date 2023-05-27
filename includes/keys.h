/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:03:35 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 22:03:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __gnu_linux__

enum e_key
{
	Key_A		= 97,
	Key_B		= 98,
	Key_C		= 99,
	Key_D		= 100,
	Key_E		= 101,
	Key_F		= 102,
	Key_G		= 103,
	Key_H		= 104,
	Key_I		= 105,
	Key_J		= 106,
	Key_K		= 107,
	Key_L		= 108,
	Key_M		= 109,
	Key_N		= 110,
	Key_O		= 111,
	Key_P		= 112,
	Key_Q		= 113,
	Key_R		= 114,
	Key_S		= 115,
	Key_T		= 116,
	Key_U		= 117,
	Key_V		= 118,
	Key_W		= 119,
	Key_X		= 120,
	Key_Y		= 121,
	Key_Z		= 122,
	Key_Left	= 65361,
	Key_Up		= 65362,
	Key_Right	= 65363,
	Key_Down	= 65364,
	Key_Plus	= 65451,
	Key_Minus	= 65453,
	Key_0		= 224,
	Key_1		= 38,
	Key_2		= 233,
	Key_3		= 34,
	Key_4		= 39,
	Key_5		= 40,
	Key_6		= 45,
	Key_7		= 232,
	Key_8		= 95,
	Key_9		= 231,
	Key_Escape	= 65307,
	Key_Space	= 32,
};
# else

enum e_key
{
	Key_A		= 0,
	Key_B		= 11,
	Key_C		= 8,
	Key_D		= 2,
	Key_E		= 14,
	Key_F		= 3,
	Key_G		= 5,
	Key_H		= 4,
	Key_I		= 34,
	Key_J		= 38,
	Key_K		= 40,
	Key_L		= 37,
	Key_M		= 46,
	Key_N		= 45,
	Key_O		= 31,
	Key_P		= 35,
	Key_Q		= 12,
	Key_R		= 15,
	Key_S		= 1,
	Key_T		= 17,
	Key_U		= 32,
	Key_V		= 9,
	Key_W		= 13,
	Key_X		= 7,
	Key_Y		= 16,
	Key_Z		= 6,
	Key_Left	= 123,
	Key_Up		= 126,
	Key_Right	= 124,
	Key_Down	= 125,
	Key_Plus	= 69,
	Key_Minus	= 78,
	Key_0		= 29,
	Key_1		= 18,
	Key_2		= 19,
	Key_3		= 20,
	Key_4		= 21,
	Key_5		= 23,
	Key_6		= 22,
	Key_7		= 26,
	Key_8		= 28,
	Key_9		= 25,
	Key_Escape	= 53,
	Key_Space	= 49,
};

# endif
#endif
