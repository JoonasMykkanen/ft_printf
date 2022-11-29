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

static int	convert_d_i_u(va_list *args, int count)
{
	char	*str;
	int		num;
	int		len;

	num = va_arg(*args, int);
	str = ft_itoa(num);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (count + len);
}

static int	ft_hexlen(unsigned long long num)
{
	int		i;
	char	c;
	int		temp;
	char	buf[17];

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
		{
			c = temp + 48;
			buf[i++] = c;
		}
		else
		{
			c = temp + 87;
			buf[i++] = c;
		}
		num = num / 16;
	}
	return (i);
}

int	convert_p(va_list *args, int count)
{
	void				*ptr;
	int					len;

	ptr = va_arg(*args, void *);
	ft_putstr_fd("0x", 1);
	len = ft_hexlen(ptr);
	ft_puthex_lower_fd(ptr, 1);
	return (count + len + 2);
}

int	convert_x(va_list *args, int count)
{
	char	*str;
	int		len;
	int		num;

	str = ft_itoa(num);
	len = ft_strlen(str);
	num = va_arg(*args, int);
	ft_puthex_lower_fd(num, 1);
	free(str);
	return (count + len);
}

int	convert_xx(va_list *args, int count)
{
	char	*str;
	int		len;
	int		num;

	str = ft_itoa(num);
	len = ft_strlen(str);
	num = va_arg(*args, int);
	ft_puthex_upper_fd(num, 1);
	free(str);
	return (count + len);
}

int	convert_precentage(args, count)
{
	ft_putchar_fd('%', 1);
	return (++count);
}

static int	choose_conversion(va_list *args, char var, int count)
{
	if (var == 'c')
		count = convert_c(args, count);
	else if (var == 's')
		count = convert_s(args, count);
	else if (var == 'd' || var == 'i' || var == 'u')
		count = convert_d_i_u(args, count);
	else if (var == 'p')
		count = convert_p(args, count);
	else if (var == 'x')
		count = convert_x(args, count);
	else if (var == 'X')
		count = convert_xx(args, count);
	else if (var == '%')
		count = convert_precentage(args, count);
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
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int 	i;
	char	var;
	int		count;
	va_list args;

	count = 0;
	va_start(args, s);
	count = print_out(s, &args, count);
	va_end(args);
	return (count);	
}

int	main()
{
	int ft;
	int og;
	void *ptr;
	char *string = "Lala land!";
	ptr = &string;

	ft = ft_printf("FT This is a character: %c\n", 'X');
	og = printf("OG This is a character: %c\n", 'X');
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This is two characters: %c and: %c\n", 'X', 'Y');
	og = printf("OG This is two characters: %c and: %c\n", 'X', 'Y');
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This is a string: %s\n", "Hello World!");
	og = printf("OG This is a string: %s\n", "Hello World!");
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This is three strings: %s and: %s andand: %s\n", "Hello World!", "Second one...", "and a third one too :-)");
	og = printf("OG This is three strings: %s and: %s andand: %s\n", "Hello World!", "Second one...", "and a third one too :-)");
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This is an integer: %d\n", 42);
	og = printf("OG This is an integer: %d\n", 42);
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This is an integer: %i\n", -42);
	og = printf("OG This is an integer: %i\n", -42);
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This zero int: %d\n", 0);
	og = printf("OG This zero int: %d\n", 0);
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This is zero hex int: %x\n", 0);
	og = printf("OG This is zero hex int: %x\n", 0);
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This is hex int: %x\n", 10);
	og = printf("OG This is hex int: %x\n", 10);
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This is a pointer: %p\n", ptr);
	og = printf("OG This is a pointer: %p\n", ptr);
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	ft = ft_printf("FT This is a precentage sign: %%\n");
	og = printf("OG This is a precentage sign: %%\n");	
	if (ft == og)
		printf("Return value SUCCESS!\n");
	else
		printf("Return value FAIL! og: %d ft: %d\n", og, ft);
	printf("\n");

	return (0);
}