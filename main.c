#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
void	test(void)
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
}
*/


int	main()
{
	

	int x = printf("og: %x \n", -1);
	int y = ft_printf("ft: %x \n", -1);

	printf("og: %d, ft: %d\n", x, y);

	

	// test();
	return (0);
}