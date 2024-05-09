# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 21:15:44 by hluiz-ma          #+#    #+#              #
#    Updated: 2024/05/08 19:02:51 by hluiz-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
CC= cc
CFLAGS= -Wall -Wextra -Werror -c
OBJS= $(SRCS:.c=.o)
LIBFT= ./libft/libft.a 
SRCS= 

RM= rm -rf  

all: $(NAME)

$(NAME):	$(OBJS)
			@make all -C libft
			@cp $(LIBFT) $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Libft.\033[0m"
			@echo "\033[0;31m𓄿 𓅓  Made by Alabar 𓄿 𓅓"

%.o: %.c #SHOW COMPILING
#$(SRCS):
			@$(CC) $(CFLAGS) -c $^ -o $@
			@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"


clean:
			@$(RM) $(OBJS) $(OBJS_BONUS)
			@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean:		clean
			@$(RM) $(NAME) 
			@make -C ./libft fclean
			@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Libft.a deleted.\033[0m"

re: 		fclean all
			
.PHONY:		all clean fclean re