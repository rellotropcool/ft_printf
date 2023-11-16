/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:11 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/16 12:48:12 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condition1(const char *fmt, int i, va_list args)
{
	if (fmt[i + 1] == 'c')
		return (condit_c(args));
	if (fmt[i + 1] == 's')
		return (condit_s(args));
	if (fmt[i + 1] == 'p')
		return (condit_p(args));
	if (fmt[i + 1] == 'd')
		return (condit_d(args));
	if (fmt[i + 1] == 'i')
		return (condit_d(args));
	if (fmt[i + 1] == 'u')
		return (condit_u(args));
	if (fmt[i + 1] == 'x')
		return (condit_h(args));
	if (fmt[i + 1] == 'X')
		return (condit_h2(args));
	if (fmt[i + 1] == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		cpt;
	int		k;

	i = 0;
	cpt = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		while (fmt[i] != '%' && fmt[i])
			cpt += write(1, &fmt[i++], 1);
		if (fmt[i] == '%')
		{
			k = condition1(fmt, i, args);
			if (k < 0)
				return (-1);
			cpt += k;
			i += 2;
		}
	}
	return (cpt);
}
