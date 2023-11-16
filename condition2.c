/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:02 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/16 12:48:03 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condit_d(va_list args)
{
	int		i;
	char	s;

	s = 0;
	i = (int)va_arg(args, int);
	if (i == -2147483648)
		return (write(1, "-2147483648", 11));
	if (i < 0)
	{
		s = 1;
		write(1, "-", 1);
		i *= -1;
	}
	return (s + write_base((size_t)i, "0123456789", 10));
}

int	condit_u(va_list args)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	return (write_base(i, "0123456789", 10));
}

int	condit_h(va_list args)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	return (write_base((size_t)i, "0123456789abcdef", 16));
}

int	condit_h2(va_list args)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	return (write_base((size_t)i, "0123456789ABCDEF", 16));
}
