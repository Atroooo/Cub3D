/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:26:33 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/13 16:06:20 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_printf_str(char c, char *str)
{
	if (c == 's')
	{
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			return (4);
		}
		return (ft_putstr_fd(str, 1), ft_strlen(str) - 2);
	}
	return (0);
}

int	ft_printf_char(char c, int nb)
{
	if (c == 'c')
		return (ft_putchar_fd(nb, 1), -1);
	return (0);
}

int	get_nbsize_hexa(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb < 16)
		return (1);
	while (nb > 0)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

static void	addr(unsigned long nb)
{
	int					digit;
	int					i;

	i = get_nbsize_hexa(nb) - 1;
	ft_putstr_fd("0x", 1);
	while (i > -1)
	{
		digit = (nb >> i * 4) & 0xf;
		ft_putchar_fd("0123456789abcdef"[digit], 1);
		i--;
	}
}

int	ft_printf_addr(char c, unsigned long nb)
{
	if (c == 'p')
		addr(nb);
	return (get_nbsize_hexa(nb));
}
