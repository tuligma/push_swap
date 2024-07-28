# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 03:28:58 by npentini          #+#    #+#              #
#    Updated: 2024/07/29 03:53:44 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = push_swap.c push_swap_error.c push_swap_error_ext.c push_swap_free.c push_swap_init.c 
COMP = cc
CFLAGS = -Wall -Wextra -Werror
DELETE = rm -rf
OBJ_DIR = objects
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)


all: all_done

$(LIBFT):
	@make -C $(FT_PRINTF_DIR) -s

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(COMP) $(CFLAGS) -o $@ -c $< -g

$(NAME) : $(OBJS) $(LIBFT)
	@$(COMP) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME);

all_done: $(OBJS) $(LIBFT) $(NAME)
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "☑️   Library compilation completed!"
	@echo "✅  Library objects has been generated!"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "☑️   Program objects compilation completed!"
	@echo "✅  Program objects has been generated!"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "☑️   Linking compilation completed!"
	@echo "✅  🇵🇺🇸🇭_🇸🇼🇦🇵 binary has been generated! "
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"

clean:
	@make -C $(LIBFT_DIR) clean -s > /dev/null 2>&1
	@$(DELETE) $(OBJ_DIR)

clean_msg : clean
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "✅  Library objects has been deleted."
	@echo "✅  Program Objects has been deleted."
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"

fclean: clean
	@make -C $(LIBFT_DIR) fclean -s > /dev/null 2>&1
	@$(DELETE) $(NAME)
	

fclean_msg: fclean
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "✅  $(LIBFT) library has been deleted."
	@echo "✅  $(NAME) binary has been deleted."
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"
	
re: fclean all

.PHONY: all clean fclean re all_done