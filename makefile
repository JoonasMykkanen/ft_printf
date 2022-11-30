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

SRC = ft_printf.c convert_c.c convert_d_i.c convert_p.c convert_precentage.c\
convert_s.c convert_x.c convert_u.c

SRC_O = $(SRC:.c=.o)

LIBFT = libft/libft.a

INCLUDES = ft_printf.h

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	mv libft/libft.a $(NAME)
	cc -c $(FLAGS) $(SRC)
	ar rc $(NAME) $(SRC_O)
	
clean:
	rm -f $(SRC_O)
	cd libft && $(MAKE) clean

fclean:
	rm -f $(SRC_O)
	rm -f $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all