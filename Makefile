# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 22:35:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/03/31 18:50:00 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libstring.a

SRCS			=	\
					delete\
					free\
					from\
					from_range\
					init\
					insert\
					join\
					push\
					pushc\
					replace\
					reset\
					resize\
					resize_cap\
					shrink\
					split\

UTILS			=	\
					bzero\
					memcpy\
					memmove\
					strlen\
					strncmp\

OFILES			=	$(SRCS:%=src/string_%.o)
UTILS_OFILES	=	$(UTILS:%=utils/ft_%.o)

INCLUDES		=	-I .\
					-I utils\

FLAGS			=	-Wall -Werror -Wextra

ifeq ($(DEBUG),1)
FLAGS			+=	-g -Og
else
FLAGS			+=	-Ofast
endif

AR_COMMAND		=	ar rs

all: $(NAME)

$(NAME): $(OFILES) $(UTILS_OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES) $(UTILS_OFILES)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	rm -f $(OFILES) $(UTILS_OFILES) test.o example.o

fclean: clean
	rm -f $(NAME) test example

re: fclean all

test: $(OFILES) $(UTILS_OFILES) test.o
	gcc -o test $(FLAGS) $(INCLUDES) $(OFILES) $(UTILS_OFILES) test.o\
		-fsanitize=address

example: $(OFILES) $(UTILS_OFILES) example.o
	gcc -o example $(FLAGS) $(INCLUDES) $(OFILES) $(UTILS_OFILES) example.o\
		-fsanitize=address
