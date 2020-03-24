# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 22:35:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/03/24 23:04:14 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libstring.a

SRCS			=	init\
					len\
					memcpy\
					push\
					resize\
					shrink\

CFILES			=	$(SRCS:%=string_%.c)
OFILES			=	$(SRCS:%=string_%.o)

FLAGS			=	-Wall -Werror -Wextra -Ofast

AR_COMMAND		=	ar rs

all: $(NAME)

$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS) -g

clean: _clean

fclean: _clean
	rm -f $(NAME) test

_clean:
	rm -f $(OFILES) test.o

re: fclean all

test: $(OFILES) test.o
	gcc -o test $(FLAGS) $(OFILES) test.o -fsanitize=address
