/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:49:35 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/13 16:06:01 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	check_str(const char *str, int index)
{
	return (str[index] == '%' && (str[index + 1] == 'd'
			|| str[index + 1] == 'u' || str[index + 1] == 'i'
			|| str[index + 1] == 'c' || str[index + 1] == '%'
			|| str[index + 1] == 'X' || str[index + 1] == 'x'
			|| str[index + 1] == 'p' || str[index + 1] == 's'));
}

static int	check_char(const char *str, int index)
{
	return (str[index] == 'd' || str[index] == 'u' || str[index] == 'i'
		|| str[index] == 'X' || str[index] == 'x' || str[index] == 'p'
		|| str[index] == 'c' || str[index] == '%' || str[index] == 's');
}

static int	print_conversion(const char *str, int index, va_list ap)
{
	if (str[index] == 'd' || str[index] == 'u' || str[index] == 'i'
		|| str[index] == 'X' || str[index] == 'x')
		return (ft_printf_nbr(str[index], va_arg(ap, int)));
	else if (str[index] == 'c')
		return (ft_printf_char(str[index], va_arg(ap, int)));
	else if (str[index] == '%')
		return (ft_putchar_fd('%', 1), -1);
	else if (str[index] == 'p')
		return (ft_printf_addr(str[index], va_arg(ap, unsigned long)));
	else if (str[index] == 's')
		return (ft_printf_str(str[index], va_arg(ap, char *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		index;
	int		len;

	va_start(ap, str);
	if (write(1, 0, 0) != 0)
		return (-1);
	index = 0;
	len = 0;
	while (str[index])
	{
		while (check_str(str, index) && str[index])
		{
			index++;
			if (check_char(str, index))
				len += print_conversion(str, index, ap);
			index++;
		}
		if (str[index] == '\0' || str[index] == '%')
			return (index + len);
		ft_putchar_fd(str[index], 1);
		index++;
	}
	va_end(ap);
	return (index + len);
}
