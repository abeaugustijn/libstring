# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 22:35:56 by aaugusti          #+#    #+#              #
#    Updated: 2020/03/30 12:04:04 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libstring.a

SRCS			=	\
					delete\
					free\
					from\
					init\
					insert\
					push\
					replace\
					resize\
					resize_cap\
					shrink\

UTILS			=	\
					bzero\
					memcpy\
					memmove\
					strlen\
					strncmp\

OFILES			=	$(SRCS:%=string_%.o)
UTILS_OFILES	=	$(UTILS:%=utils/ft_%.o)

FLAGS			=	-Wall -Werror -Wextra -Ofast

AR_COMMAND		=	ar rs

all: $(NAME)

$(NAME): $(OFILES) $(UTILS_OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES) $(UTILS_OFILES)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS) -g

clean:
	rm -f $(OFILES) $(UTILS_OFILES) test.o example.o

fclean: clean
	rm -f $(NAME) test example

re: fclean all

test: $(OFILES) $(UTILS_OFILES) test.o
	gcc -o test $(FLAGS) $(OFILES) $(UTILS_OFILES) test.o -fsanitize=address

example: $(OFILES) $(UTILS_OFILES) example.o
	gcc -o example $(FLAGS) $(OFILES) $(UTILS_OFILES) example.o -fsanitize=address
