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

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_memmove.c ft_memset.c\
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strncmp.c\
ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_memchr.c ft_memcmp.c\
ft_strtrim.c ft_strnstr.c ft_calloc.c ft_strmapi.c ft_striteri.c ft_split.c\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c\
ft_puthex_lower_fd.c ft_puthex_upper_fd.c ft_memrcpy.c\

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

GNL_O = get_next_line.o get_next_line_utils.o

PRINTF = ft_printf/ft_printf.c ft_printf/convert_c.c ft_printf/convert_d_i_u.c\
ft_printf/convert_p.c ft_printf/convert_precentage.c ft_printf/convert_s.c\
ft_printf/convert_x.c

PRINTF_O = ft_printf.o convert_c.o convert_d_i_u.o convert_p.o convert_precentage.o\
convert_s.o convert_x.o
 
SRC_O = $(SRC:.c=.o)

INCLUDES = libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

all: $(NAME)

$(NAME):
	cc -c $(FLAGS) $(SRC) $(GNL) $(PRINTF)
	ar rc $(NAME) $(SRC_O) $(GNL_O) $(PRINTF_O)

clean:
	rm -f $(SRC_O) $(GNL_O) $(PRINTF_O) 

fclean:
	rm -f $(SRC_O) $(GNL_O) $(PRINTF_O)
	rm -f $(NAME)

re: fclean all