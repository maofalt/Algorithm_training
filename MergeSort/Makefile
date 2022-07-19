# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motero <motero@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 18:38:23 by motero            #+#    #+#              #
#    Updated: 2022/07/19 15:59:52 by motero           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#=============================================================================#
#                                 HEADERS                                     #
#=============================================================================#

HDR_NAME = PushSwap.h #here other headers too
HDR_DIR = includes/
HDRS = $(addprefix $(HDR_DIR), $(HDR_NAME))
HDR_INC = -I./includes

#=============================================================================#
#                                 LIBRARIES                                     #
#=============================================================================#

LIBFT_HDIR = libft/includes
LIBFT_HDIR_INC = -I./libft/includes/
LIB_BINARY = -L./libft -lft
LIBFT = libft/libft.a

#=============================================================================#
#                               SOURCES                                       #
#=============================================================================#

SRCS_DIR_PS = sources/
SRCS_NAME_PS = main.c \
ft_calculate_mov_functions.c\
ft_data_functions.c \
ft_instructions_functions.c \
ft_list_functions.c \
ft_math_functions.c \
ft_move_functions.c \
ft_node_functions.c \
ft_parsing.c \
ft_sorting_functions.c \
ft_stack_operations.c

SRCS_PS = $(addprefix $(SRCS_DIR_PS), $(SRCS_NAME_PS))

#=============================================================================#
#                                OBJECTS                                      #
#=============================================================================#

OBJS_PATH = objs/
OBJS_NAME = $(SRCS_NAME_PS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

#=============================================================================#
#                          COMPILATOR & FLAGS                                 #
#=============================================================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBA = ar rc
LIBS = ranlib

RM = rm -Rf

#=============================================================================#
#                          debug, leaks                                 #
#=============================================================================#

PROFILER = push_swap
OBJS_NAME_PROFILER = $(SRCS_NAME_PS:.c=.o)
OBJS_PROFILER = $(addprefix $(OBJS_PATH), $(OBJS_NAME_PROFILER))
PROFILER_FLAG = -pg

#=============================================================================#
#                                COLOURS                                      #
#=============================================================================#

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

#=============================================================================#
#                                RULES                                        #
#=============================================================================#

all: check_libft project ${NAME} ${HDRS}
		@echo "Project is ready"

check_libft:
		@echo "Checking libft ..."
		@make -C libft

project:
		@echo "Checking project ..."

$(OBJS_PATH):
		@mkdir $@
		@echo "\t [ $(GREEN)✔$(NONE)] $@directory"

$(OBJS_PATH)%.o: $(SRCS_DIR_PS)%.c $(HDRS) $(LIBFT)
		@$(CC) $(CFLAGS) $(HDR_INC) $(LIBFT_HDIR_INC) -o $@ -c $<
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ objet push_swap"

$(NAME): $(OBJS_PATH) $(OBJS) $(LIBFT) $(HDRS)
		@echo "\t Wait for it ..."
		@echo "\t─────▄▀▄─────▄▀▄"
		@echo "\t────▄█░░▀▀▀▀▀░░█▄"
		@echo "\t▄▄──█░░░░░░░░░░░█──▄▄"
		@echo "\t▄▄█─█░░▀░░┬░░▀░░█─█▄▄█"
		@$(CC) $(CFLAGS) $(LIB_BINARY) $(OBJS) -o $@
		@echo "\t[ $(GREEN)✔$(NONE) ] push_swap"

$(PROFILER) : $(OBJS_PATH) $(OBJS) $(LIBFT) $(HDRS)

profiler:
		${PROFILER}

clean:
		@${RM} $(OBJS_PATH)
		@echo "\t[ $(RED)✗$(NONE) ] $(OBJ_DIR) directory"
		@make -C ./libft/ clean

fclean: clean
		@rm -f ${NAME}
		@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
		@make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re
