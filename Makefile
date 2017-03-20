# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 09:13:07 by ysan-seb          #+#    #+#              #
#    Updated: 2016/12/19 10:54:53 by ysan-seb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   fillit

SRCS	=	check_entry.c tetri_split.c utility.c ft_libft.c main.c  \
            init_and_read.c backtracking.c ft_libft2.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

HEADER	=	-I./

RM	    =	rm -f

all	: $(NAME)

$(NAME)	: $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(HEADER)
	@echo "\033[1m\033[32m[ ✔ ]Compilation succes :\033[0m $(NAME)"

clean	:
	@$(RM) $(OBJS)
	@echo "\033[1m\033[32m[ ✔ ]Deleting succes :\033[0m $(OBJS)"

fclean	:	clean
	@$(RM) $(NAME)
	@echo "\033[1m\033[32m[ ✔ ]Deleting Succes :\033[0m $(NAME)"

re	:	fclean all
