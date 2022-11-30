# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:22:41 by jmykkane          #+#    #+#              #
#    Updated: 2022/10/24 14:22:53 by jmykkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINTF_SRC = ft_printf.c convert_c.c convert_d_i_u.c convert_p.c convert_precentage.c\
convert_s.c convert_x.c

PRINTF_SRC_O = $(PRINTF_SRC:.c=.o)

LIBFT = libft/libft.a

INCLUDES = ft_printf.h

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	cc -c $(FLAGS) $(PRINTF_SRC)
	ar rc $(NAME) $(PRINTF_SRC_O)
	

clean:
	rm -f $(PRINTF_SRC_O)
	cd libft && $(MAKE) clean

fclean:
	rm -f $(PRINTF_SRC_O)
	rm -f $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all