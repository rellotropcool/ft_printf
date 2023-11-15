#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

int	ft_printf(const char* fmt, ...);
int	write_base(size_t s, char *base, size_t len);
int	condit_c(va_list args);
int	condit_s(va_list args);
int	condit_p(va_list args);
int	condit_d(va_list args);

#endif
