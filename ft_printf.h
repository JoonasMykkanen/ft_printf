
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

#ifndef LIBFT_H
# include "libft/libft.h"
#endif

int	ft_printf(const char *s, ...);
int	convert_precentage(int count);
int	ft_hexlen(unsigned long long num);
int	convert_c(va_list *args, int count);
int	convert_u(va_list *args, int count);
int	convert_s(va_list *args, int count);
int	convert_x(va_list *args, int count);
int	convert_p(va_list *args, int count);
int	convert_xx(va_list *args, int count);
int	convert_d_i(va_list *args, int count);

#endif