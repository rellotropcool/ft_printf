/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:48:20 by aule-bre          #+#    #+#             */
/*   Updated: 2023/11/16 12:48:22 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);
int	write_base(size_t s, char *base, size_t len);
int	condit_c(va_list args);
int	condit_s(va_list args);
int	condit_p(va_list args);
int	condit_d(va_list args);
int	condit_u(va_list args);
int	condit_h(va_list args);
int	condit_h2(va_list args);

#endif
