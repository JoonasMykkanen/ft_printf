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

SRC = ft_printf.c convert_c.c convert_d_i_u.c convert_p.c convert_precentage.c\
convert_s.c convert_x.c

SRC_O = $(SRC:.c=.o)

INCLUDES = printf.h libft/libft.h

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

all: $(NAME)

$(NAME):
	cc -c $(FLAGS) $(SRC) $(GNL) $(PRINTF)
	ar rc $(NAME) $(SRC_O) $(GNL_O) $(PRINTF_O)

clean:
	rm -f $(SRC_O)

fclean:
	rm -f $(SRC_O)
	rm -f $(NAME)

re: fclean all