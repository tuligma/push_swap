# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 08:02:10 by npentini          #+#    #+#              #
#    Updated: 2024/07/29 03:40:29 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include colors.mk

NAME = libft.a
SRCS = ft_standard/ft_atoi.c ft_standard/ft_isalnum.c \
		ft_standard/ft_isalpha.c ft_standard/ft_isascii.c \
		ft_standard/ft_isdigit.c ft_standard/ft_isprint.c \
		ft_standard/ft_itoa.c ft_standard/ft_tolower.c \
		ft_standard/ft_toupper.c \
		ft_memory/ft_bzero.c ft_memory/ft_calloc.c ft_memory/ft_memchr.c \
		ft_memory/ft_memcmp.c ft_memory/ft_memcpy.c ft_memory/ft_memmove.c \
		ft_memory/ft_memset.c \
		ft_string/ft_split.c ft_string/ft_strchr.c \
		ft_string/ft_strdup.c ft_string/ft_striteri.c \
		ft_string/ft_strjoin.c ft_string/ft_strlcat.c \
		ft_string/ft_strlcpy.c ft_string/ft_strlen.c \
		ft_string/ft_strmapi.c ft_string/ft_strncmp.c \
		ft_string/ft_strnstr.c ft_string/ft_strrchr.c \
		ft_string/ft_strtrim.c ft_string/ft_substr.c \
		ft_list/ft_lstadd_back.c ft_list/ft_lstadd_front.c ft_list/ft_lstclear.c \
		ft_list/ft_lstdelone.c ft_list/ft_lstiter.c ft_list/ft_lstlast.c \
		ft_list/ft_lstmap.c ft_list/ft_lstnew.c ft_list/ft_lstsize.c \
		ft_io/ft_putchar_fd.c ft_io/ft_putendl_fd.c ft_io/ft_putnbr_fd.c \
		ft_io/ft_putstr_fd.c 
M_SRCS = ft_io/get_next_line/mandatory/get_next_line.c \
		ft_io/get_next_line/mandatory/get_next_line_utils.c \
		ft_io/ft_printf/mandatory/ft_printf_process1.c \
		ft_io/ft_printf/mandatory/ft_printf_process2.c \
		ft_io/ft_printf/mandatory/ft_printf_utils.c \
		ft_io/ft_printf/mandatory/ft_printf.c
B_SRCS = ft_io/get_next_line/bonus/get_next_line_bonus.c \
		ft_io/get_next_line/bonus/get_next_line_utils_bonus.c\
		ft_io/ft_printf/bonus/ft_printf_bonus.c \
		ft_io/ft_printf/bonus/ft_printf_flag_utils_bonus.c \
		ft_io/ft_printf/bonus/ft_printf_print_process1_bonus.c \
		ft_io/ft_printf/bonus/ft_printf_print_process1_ext_bonus.c \
		ft_io/ft_printf/bonus/ft_printf_print_process2_bonus.c \
		ft_io/ft_printf/bonus/ft_printf_process1_bonus.c \
		ft_io/ft_printf/bonus/ft_printf_process2_bonus.c \
		ft_io/ft_printf/bonus/ft_printf_utils_bonus.c
INCS = includes/
COMP = cc -c
CFLAGS = -Wall -Wextra -Werror
DELETE = rm -rf
LIB_CREATE = ar rcs
RANLIB = ranlib
OBJ_DIR = ../objects/libft
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
M_OBJS = $(M_SRCS:%.c=$(OBJ_DIR)/%.o)
B_OBJS = $(B_SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(COMP) $(CFLAGS) -I $(INCS) -o $@ $<

$(NAME): $(OBJS) $(M_OBJS)
	@$(LIB_CREATE) $(NAME) $(OBJS) $(M_OBJS)

bonus: $(B_OBJS) $(OBJS)
	@$(LIB_CREATE) $(NAME) $(OBJS) $(B_OBJS)

clean:
	@$(DELETE) $(OBJ_DIR)

fclean: clean
	@$(DELETE) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
