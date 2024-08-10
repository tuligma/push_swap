# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 03:28:58 by npentini          #+#    #+#              #
#    Updated: 2024/08/10 12:13:47 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = src/error/push_swap_error.c \
		src/error/push_swap_error_ext.c \
		src/init/push_swap_init.c \
		src/init/push_swap_presort.c \
		src/init/push_swap_stack.c \
		src/protocols/push_swap_protocols_single.c \
		src/protocols/push_swap_protocols_double.c \
		src/protocols/push_swap_protocols_execute_print.c \
		src/partition/push_swap_partition_helper.c \
		src/partition/push_swap_partition_moves.c \
		src/partition/push_swap_partition_conditions.c \
		src/partition/push_swap_partition.c \
		src/merge/push_swap_merge_insert_position.c \
		src/merge/push_swap_merge_remove_position.c \
		src/merge/push_swap_merge_execution.c \
		src/utils/push_swap_algorithm_utils.c \
		src/utils/push_swap_free.c \
		src/utils/push_swap_free_ext.c \
		src/main/push_swap_algorithm_per_args.c \
		src/main/push_swap.c
COMP = cc
CFLAGS = -Wall -Wextra -Werror
DELETE = rm -rf
OBJ_DIR = objects
OBJ_PUSH_DIR = $(OBJ_DIR)/$(NAME)
LIBFT_NAME = libft.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)
OBJS = $(SRCS:%.c=$(OBJ_PUSH_DIR)/%.o)


all: check_build

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(OBJ_PUSH_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(COMP) $(CFLAGS) -o $@ -c $< -g

$(NAME) : $(OBJS) $(LIBFT)
	@$(COMP) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME);
	@echo "\n〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "☑️   🇱🇮🇧🇫🇹	compilation completed!      🆗"
	@echo "✅  🇱🇮🇧🇫🇹	objects has been generated! 🆗"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "☑️   🇵🇺🇸🇭_🇸🇼🇦🇵	compilation completed!      🆗"
	@echo "✅  🇵🇺🇸🇭_🇸🇼🇦🇵	objects has been generated! 🆗"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "☑️   Linking	compilation completed!      🆗"
	@echo "✅  🇵🇺🇸🇭_🇸🇼🇦🇵	binary has been generated!  🆗"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"

check_build:
	@if [ -e $(NAME) ]; then \
		echo "\n〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"; \
		echo "🚫 🇵🇺🇸🇭_🇸🇼🇦🇵 is already generated, What else do you want? 🚫"; \
		echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"; \
		else \
			$(MAKE) $(NAME) -s; \
	fi

clean:
	@make -C $(LIBFT_DIR) clean -s > /dev/null 2>&1
	@$(DELETE) $(OBJ_DIR)
	@echo "\n〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "✅  🇱🇮🇧🇫🇹	objects has been deleted. 🚮"
	@echo "✅  🇵🇺🇸🇭_🇸🇼🇦🇵	objects has been deleted. 🚮"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"

fclean: clean
	@make -C $(LIBFT_DIR) fclean -s > /dev/null 2>&1
	@$(DELETE) $(NAME)
	@echo "\n〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "✅  🇱🇮🇧🇫🇹	library has been deleted. 🚮"
	@echo "✅  🇵🇺🇸🇭_🇸🇼🇦🇵	binary has been deleted.  🚮"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"
	
re: fclean all

.PHONY: all clean fclean re