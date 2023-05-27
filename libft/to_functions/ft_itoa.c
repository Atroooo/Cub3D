/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:27:25 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/13 16:05:56 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static long long int	get_divider(long long int nb)
{
	long int	divider;

	if (nb == 0)
	{
		divider = 1;
		return (divider);
	}
	if (nb < 0)
		nb *= -1;
	divider = 1;
	while (nb > 0)
	{
		divider *= 10;
		nb /= 10;
	}
	divider = divider / 10;
	return (divider);
}

static	int	get_mallocsize(long long int nb)
{
	int				count;

	count = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*number;
	int				index;
	long long int	divider;
	long long int	tempnb;

	divider = get_divider(n);
	number = malloc(sizeof(char) * (get_mallocsize(n) + 2));
	if (!number)
		return (NULL);
	index = 0;
	tempnb = n;
	if (n < 0)
	{
		tempnb *= -1;
		number[index++] = '-';
	}
	while (divider != 0)
	{
		number[index++] = "0123456789"[tempnb / divider];
		tempnb = tempnb - divider * (tempnb / divider);
		divider /= 10;
	}
	number[index] = '\0';
	return (number);
}
