/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:22:05 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/13 16:06:31 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static	int	get_nbsize(long int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static void	convert_to_hexa(long int nbr, char *base, int check)
{
	long int	nbtemp;

	nbtemp = nbr;
	if (nbr == 0 && check == 0)
		ft_putchar_fd('0', 1);
	if (nbtemp < 0)
	{
		ft_putchar_fd('-', 1);
		nbtemp *= -1;
	}
	if (nbtemp > 0)
	{
		convert_to_hexa(nbtemp / 16, base, 1);
		ft_putchar_fd(base[nbtemp % 16], 1);
	}
}

int	ft_printf_nbr(char c, int nb)
{
	if (c == 'd')
		return (ft_putnbr_fd((int)nb, 1), get_nbsize(nb) - 2);
	else if (c == 'i')
		return (ft_putnbr_fd((int)nb, 1), get_nbsize(nb) - 2);
	else if (c == 'u')
		return (ft_putnbr_fd((unsigned int)nb, 1),
			get_nbsize((unsigned int)nb) - 2);
	else if (c == 'X')
	{
		convert_to_hexa((unsigned int)nb, "0123456789ABCDEF", 0);
		if (nb < 0)
			return (get_nbsize((unsigned int)nb) - 4);
		return (get_nbsize_hexa(nb) - 2);
	}
	else if (c == 'x')
	{
		convert_to_hexa((unsigned int)nb, "0123456789abcdef", 0);
		if (nb < 0)
			return (get_nbsize((unsigned int)nb) - 4);
		return (get_nbsize_hexa(nb) - 2);
	}
	return (0);
}
