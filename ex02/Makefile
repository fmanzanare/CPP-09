# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 16:48:15 by fmanzana          #+#    #+#              #
#    Updated: 2023/08/08 17:01:42 by fmanzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =	PmergeMe.cpp\
		main.cpp

OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "PmergeMe compiled!"

%.o:		%.cpp
	@$(CC) $(CFLAGS) -c $<

clean:
	@rm -f $(OBJS)

fclean:		clean
	@rm -f $(NAME)
	@echo "Everything cleaned!"

re:			fclean all

.PHONY:	all clean fclean re
