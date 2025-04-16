# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 11:00:46 by gmaldona          #+#    #+#              #
#    Updated: 2025/04/16 11:14:05 by gmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS :=

OBJS := $(SRCS:.c=.o)

NAME := solong.a

FTPRINTF := ftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

ARRU = ar -ru

RM = rm -f

$(NAME): 	$(OBJS)
			$(MAKE) -C ./libft aux
			$(ARRU) $(NAME) $(OBJS) 
		

all:
			make $(NAME)

clean: 
			$(RM) $(OBJS)
			cd ./libft && $(MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			cd ./libft && $(MAKE) fclean

re:			fclean all

bonus:
			make $(NAME)
		
.PHONY: 	all clean fclean re bonus
