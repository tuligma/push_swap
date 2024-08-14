# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 03:28:58 by npentini          #+#    #+#              #
#    Updated: 2024/08/14 18:08:57 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
SRCS = mandatory/error/push_swap_error.c \
		mandatory/error/push_swap_error_ext.c \
		mandatory/init/push_swap_init.c \
		mandatory/init/push_swap_presort.c \
		mandatory/init/push_swap_stack.c \
		mandatory/protocols/push_swap_protocols_single.c \
		mandatory/protocols/push_swap_protocols_double.c \
		mandatory/protocols/push_swap_protocols_execute_print.c \
		mandatory/partition/push_swap_partition_helper.c \
		mandatory/partition/push_swap_partition_moves.c \
		mandatory/partition/push_swap_partition_conditions.c \
		mandatory/partition/push_swap_partition.c \
		mandatory/merge/push_swap_merge_insert_position.c \
		mandatory/merge/push_swap_merge_remove_position.c \
		mandatory/merge/push_swap_merge_execution.c \
		mandatory/utils/push_swap_algorithm_utils.c \
		mandatory/utils/push_swap_free.c \
		mandatory/utils/push_swap_free_ext.c \
		mandatory/main/push_swap_algorithm_per_args.c
MAIN_SRCS = mandatory/main/push_swap.c
B_SRCS = bonus/checker.c \
	bonus/checker_protocols_extraction.c \
	bonus/checker_protocols_execution_conditions.c \
	bonus/checker_protocols_execution.c
COMP = cc
CFLAGS = -Wall -Wextra -Werror
DELETE = rm -rf
OBJ_DIR = objects
OBJ_PUSH_DIR = $(OBJ_DIR)/$(NAME)
LIBFT_NAME = libft.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)
OBJS = $(SRCS:%.c=$(OBJ_PUSH_DIR)/%.o)
MAIN_OBJS = $(MAIN_SRCS:%.c=$(OBJ_PUSH_DIR)/%.o) \
	$(OBJS)
B_OBJS = $(B_SRCS:%.c=$(OBJ_PUSH_DIR)/%.o) \
	$(SRCS:%.c=$(OBJ_PUSH_DIR)/%.o)

all: check_build_mandatory

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(OBJ_PUSH_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(COMP) $(CFLAGS) -o $@ -c $< -g

$(NAME) : $(MAIN_OBJS) $(LIBFT)
	@$(COMP) $(CFLAGS) $(MAIN_OBJS) $(LIBFT) -o $(NAME) -g
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

$(CHECKER): $(B_OBJS) $(LIBFT)
	@$(COMP) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(CHECKER);

bonus: check_build_bonus
	@echo "\n〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "☑️   🇱🇮🇧🇫🇹	compilation completed!      🆗"
	@echo "✅  🇱🇮🇧🇫🇹	objects has been generated! 🆗"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "☑️   🇨🇭🇪🇨🇰🇪🇷	compilation completed!      🆗"
	@echo "✅  🇨🇭🇪🇨🇰🇪🇷	objects has been generated! 🆗"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "☑️   Linking	compilation completed!      🆗"
	@echo "✅  🇨🇭🇪🇨🇰🇪🇷	binary has been generated!  🆗"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"

check_build_mandatory:
	@if [ -e $(NAME) ]; then \
		echo "\n〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"; \
		echo "🚫 🇵🇺🇸🇭_🇸🇼🇦🇵 is already generated, What else do you want? 🚫"; \
		echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"; \
		else \
			$(MAKE) $(NAME) -s; \
	fi

check_build_bonus:
	@if [ -e $(CHECKER) ]; then \
		echo "\n〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"; \
		echo "🚫 🇱🇮🇧🇫🇹 is already generated, What else do you want? 🚫"; \
		echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"; \
		else \
			$(MAKE) $(CHECKER) -s; \
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
	@$(DELETE) $(NAME) $(CHECKER)
	@echo "\n〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️"
	@echo "✅  🇱🇮🇧🇫🇹	library has been deleted. 🚮"
	@echo "✅  🇵🇺🇸🇭_🇸🇼🇦🇵	binary has been deleted.  🚮"
	@echo "✅  🇨🇭🇪🇨🇰🇪🇷	binary has been deleted.  🚮"
	@echo "〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️\n"
	
re: fclean all

.PHONY: all clean fclean re