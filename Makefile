# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 03:28:58 by npentini          #+#    #+#              #
#    Updated: 2024/07/27 05:06:29 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = push_swap.c
LIB_SRCS = lib/src/ft_bzero.c \
			lib/src/ft_calloc.c \
			lib/src/ft_isdigit.c \
			lib/src/ft_issign.c \
			lib/src/ft_isspace.c \
			lib/src/ft_split.c
COMP = cc
CFLAGS = -Wall -Wextra -Werror
DELETE = rm -rf
OBJ_DIR = objects
FT_PRINTF_DIR = ./lib/src/ft_printf
FT_PRINTF_FILE = $(FT_PRINTF_DIR)/libftprintf.a
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
LIB_OBJS = $(LIB_SRCS:lib/src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(COMP) $(CFLAGS) -o $@ -c $< -g
	@echo "\n☑️   Object compilation completed!"
	@echo "✅  Objects has been generated to $(OBJ_DIR).\n"

$(OBJ_DIR)/%.o: lib/src/%.c
	@mkdir -p $(@D)
	@$(COMP) $(CFLAGS) -o $@ -c $< -g

$(FT_PRINTF_FILE):
	@make -C $(FT_PRINTF_DIR) -s
	@echo "\n☑️   Library compilation completed!"
	@echo "✅  Library objects has been generated to $(OBJ_DIR).\n"

$(NAME) : $(OBJS) $(LIB_OBJS) $(FT_PRINTF_FILE)
	@$(COMP) $(CFLAGS) $(OBJS) $(LIB_OBJS) $(FT_PRINTF_FILE) -o $(NAME);
	@echo "\n☑️   Linking compilation completed!"
	@echo "✅  🇵🇺🇸🇭_🇸🇼🇦🇵 binary has been generated. \n"

clean:
	@$(DELETE) $(OBJ_DIR)
	@make -C $(FT_PRINTF_DIR) clean -s
	@echo "\n✅  Objects has been deleted."

fclean: clean
	@$(DELETE) $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean -s > /dev/null 2>&1
	@echo "✅  $(NAME) binary has been deleted.\n"

re: fclean all

.PHONY: all clean fclean re