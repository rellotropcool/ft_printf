#include "ft_printf.h"

int	write_base(size_t s, char *base, size_t len)
{
	if (s >= len)
		return (write_base(s / len, base, len) +
			write_base(s % len, base, len));
	return (write(1, &base[s % len], 1));
}

int	condit_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

int	condit_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	condit_p(va_list args)
{
	void	*v;
	size_t i;

	v = (void*)va_arg(args, void *);
	i = (size_t)v;
	if(!i)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) +
		write_base(i, "0123456789abcdef", 16));
}
