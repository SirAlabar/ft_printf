# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 21:15:44 by hluiz-ma          #+#    #+#              #
#    Updated: 2024/12/02 14:06:01 by hluiz-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for prettier output
GREEN		= \033[0;32m
RED		= \033[0;31m
RESET		= \033[0m
BLUE		= \033[0;34m
YELLOW		= \033[0;33m

# Project settings
NAME		= libftprintf.a
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -rf

# Directories
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
SRC_DIR		= ./src
INCLUDES	= ./include
BONUS_DIR	= ./bonus

# Source files
SRCS		= $(SRC_DIR)/ft_printf.c \
		  $(SRC_DIR)/ft_format.c \
		  $(SRC_DIR)/ft_format_handler.c \
		  $(SRC_DIR)/ft_handler_flags.c \
		  $(SRC_DIR)/ft_output.c \
		  $(SRC_DIR)/ft_output_flags.c \
		  $(SRC_DIR)/ft_print_left.c \
		  $(SRC_DIR)/ft_print_hex.c		  

# Object files
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

# Include flags
INCLUDES_FLAGS	= -I$(INCLUDES) -I$(LIBFT_DIR)

# Default target
all: $(NAME)

# Main program compilation
$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf library compiled successfully!$(RESET)"
	@echo "$(RED)𓄿 𓅓  Made by Alabar 𓄿 𓅓$(RESET)"

# Bonus compilation
bonus: $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf library compiled successfully!$(RESET)"
	@echo "$(RED)𓄿 𓅓  Made by Alabar 𓄿 𓅓$(RESET)"

# Compile source files
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES_FLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $<$(RESET)"

# Clean object files
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(YELLOW)Object files cleaned!$(RESET)"

# Full cleanup
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)Everything cleaned!$(RESET)"

# Rebuild everything
re: fclean all

.PHONY: all bonus clean fclean re