#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

static int	convert_c(va_list *args, int count)
{
	char	c;

	c = va_arg(*args, char);
	ft_putchar_fd(c, 1);
	return (++count);
}

static int	convert_s(va_list *args, int count)
{
	const char	*str;
	int			len;

	str = va_arg(*args, const char *);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	return (count + len);
}

static int	convert_d_or_i(va_list *args, int count)
{
	char	*str;
	int		num;
	int		len;

	num = va_arg(*args, int);
	str = ft_itoa(num);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	return (count = len);
}

int	convert_p(va_list *args, int count)
{
	unsigned long long	num;
	void				*ptr;
	char				*str;
	int					len;

	ptr = va_arg(*args, void *);
	ft_putstr_fd("0x", 1);

	num = ptr;
	str = ft_itoa(num);
	len = ft_strlen(str);
	ft_puthex_fd(num, 1);
	return (count + len + 2);
}

int	convert_u(va_list *args, int count)
{

}

int	convert_x(va_list *args, int count)
{
	int num;

	num = va_arg(*args, int);
	ft_puthex_fd(num, 1);
}

int	convert_xx(va_list *args, int count)
{

}

static int	choose_conversion(va_list *args, char var, int count)
{
	if (var == 'c')
		count = convert_c(args, count);
	else if (var == 's')
		count = convert_s(args, count);
	else if (var == 'd' || var == 'i')
		count = convert_d_or_i(args, count);
	else if (var == 'p')
		count = convert_p(args, count);
	else if (var == 'u')
		count = convert_u(args, count);
	else if (var == 'x')
		count = convert_x(args, count);
	else if (var == 'X')
		count = convert_xx(args, count);
	return (count);
}

static int	print_out(const char *s, va_list *args, int count)
{
	int		i;
	char	var;
	int		mode;

	i = -1;
	mode = 0;
	while (s[++i] != '\0')
	{
		if (mode == 0)
		{
			if (s[i] == '%')
				mode = 1;
			else
			{
				ft_putchar_fd(s[i], 1);
				count++;
			}
		}
		else if (mode == 1)
		{
			mode = 0;
			var = s[i];
			count = choose_conversion(args, var, count);
		}
	}
}

int	ft_printf(const char *s, ...)
{
	int 	i;
	char	var;
	int		count;
	va_list args;

	va_start(args, s);

	count = print_out(s, &args, count);

	va_end(args);
	return (count);	
}

int	main()
{
	void *ptr;
	char *string = "Lala land!";
	ptr = &string;

	ft_printf("This is a character: %c\n", 'X');
	ft_printf("This is two characters: %c and: %c\n", 'X', 'Y');
	ft_printf("This is a string: %s\n", "Hello World!");
	ft_printf("This is three strings: %s and: %s andand: %s\n", "Hello World!", "Second one...", "and a third one too :-)");
	ft_printf("This is an integer: %d\n", 42);
	ft_printf("This is an integer: %i\n", -42);
	ft_printf("This zero int: %d\n", 0);
	ft_printf("This is zero hex int: %x\n", 0);
	ft_printf("This is hex int: %x\n", 10);
	printf("OG = This is a pointer: %p\n", ptr);
	ft_printf("This is a pointer: %p\n", ptr);

	return (0);
}