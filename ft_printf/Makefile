# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 13:22:11 by gmaldona          #+#    #+#              #
#    Updated: 2025/04/16 18:02:13 by gmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ph_reader.c ph_writer.c

OBJS = $(SRCS:.c=.o)

NAME = ft_printf.a 

LIBFT = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar -rcs

ARRU = ar -ru

RM = rm -f

PARENT_LIB = so_long.a

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

re:		fclean all

aux:		$(OBJS)	
		make $(NAME)
		cp $(NAME) ./../$(PARENT_LIB)

bonus:
		make $(NAME)
		
.PHONY: all clean fclean re bonus