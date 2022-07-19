# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motero <motero@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 18:38:23 by motero            #+#    #+#              #
#    Updated: 2022/07/19 21:31:59 by motero           ###   ########.fr        #
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
#                                 Profiler                                    #
#=============================================================================#

PROFILE = push_swap_prof

OBJS_PATH_PROFILER = objs_prof/
OBJS_NAME_PROFILER = $(SRCS_NAME_PS:.c=.o)
OBJS_PROFILER = $(addprefix $(OBJS_PATH_PROFILER), $(OBJS_NAME_PROFILER))

PROFILER_FLAG = -g3 -pg

#=============================================================================#
#                                 Fsanitize                                    #
#=============================================================================#

SANITIZE = push_swap_sanitize

OBJS_PATH_SANITIZE = objs_sanitize/
OBJS_NAME_SANITIZE = $(SRCS_NAME_PS:.c=.o)
OBJS_SANITIZE = $(addprefix $(OBJS_PATH_SANITIZE), $(OBJS_NAME_SANITIZE))

SANITIZE_FLAG = -g3 -fsanitise=address

#=============================================================================#
#                                 Valgrind                                    #
#=============================================================================#

VALGND = push_swap_valgrind

OBJS_PATH_SVALGND = objs_valgrind/
OBJS_NAME_VALGND = $(SRCS_NAME_PS:.c=.o)
OBJS_VALGND = $(addprefix $(OBJS_PATH_VALGND), $(OBJS_NAME_VALGND))

VALGND_FLAG = -g3

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

#=============================================================================#
#                                RULES   PROFILER                             #
#=============================================================================#

#To xecute as follows :make sanitizer var="1 2 3"

prof: fclean check_libft project ${PROFILE} ${HDRS} run execute_profiler

execute_profiler :
		@gprof -b ${PROFILE} gmon.out > analysis.txt
		@echo "\t[ $(GREEN) Profling done!$(NONE) ]"
		@echo "========================================"
		@cat analysis.txt

$(OBJS_PATH_PROFILER):
		@mkdir $@
		@echo "\t [ $(GREEN)✔$(NONE)] $@directory"

$(OBJS_PATH_PROFILER)%.o: $(SRCS_DIR_PS)%.c $(HDRS) $(LIBFT)
		@$(CC) $(CFLAGS) $(PROFILER_FLAG) $(HDR_INC) $(LIBFT_HDIR_INC) -o $@ -c $<
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ objet push_swap_prof"

$(PROFILE) : $(OBJS_PATH_PROFILER) $(OBJS_PROFILER) $(LIBFT) $(HDRS)
		@echo "\t PROFILER COMPILATION"
		@echo "\t─────▄▀▄─────▄▀▄"
		$(CC) $(CFLAGS) $(PROFILER_FLAG) $(LIB_BINARY) $(OBJS_PROFILER) -o $@
		@echo "\t[ $(GREEN)✔$(NONE) ] push_swap_prof"

#=============================================================================#
#                                RULES   SANITIZER                            #
#=============================================================================#

#to launch as folows  : make sanitizer var="1 2 3"
sanitizer: fclean check_libft project ${SANITIZE} ${HDRS} run

$(OBJS_PATH_SANITIZE):
		@mkdir $@
		@echo "\t [ $(GREEN)✔$(NONE)] $@directory"

$(OBJS_PATH_SANITIZE)%.o: $(SRCS_DIR_PS)%.c $(HDRS) $(LIBFT)
		@$(CC) $(CFLAGS) $(SANITIZE_FLAG) $(HDR_INC) $(LIBFT_HDIR_INC) -o $@ -c $<
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ objet push_swap_sanitize"

$(SANITIZE) : $(OBJS_PATH_SANITIZE) $(OBJS_SANITIZE) $(LIBFT) $(HDRS)
		@echo "\t FSANITIZE COMPILATION"
		@echo "\t─────▄▀▄─────▄▀▄"
		$(CC) $(CFLAGS) $(SANITIZE_FLAG) $(LIB_BINARY) $(OBJS_SANITIZE) -o $@
		@echo "\t[ $(GREEN)✔$(NONE) ] push_swap_sanitize"

#make run_sanitize with good run

#=============================================================================#
#                                RULES  VALGRIND                              #
#=============================================================================#

#to launch as folows  : make valgnd var="1 2 3"
valgnd: fclean check_libft project ${VALGND} ${HDRS} run_valgnd

$(OBJS_PATH_VALGND):
		@mkdir $@
		@echo "\t [ $(GREEN)✔$(NONE)] $@directory"

$(OBJS_PATH_VALGND)%.o: $(SRCS_DIR_PS)%.c $(HDRS) $(LIBFT)
		@$(CC) $(CFLAGS) $(VALGND_FLAG) $(HDR_INC) $(LIBFT_HDIR_INC) -o $@ -c $<
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ objet push_swap_valgrind"

$(VALGND) : $(OBJS_PATH_VALGND) $(OBJS_VALGND) $(LIBFT) $(HDRS)
		@echo "\t VALGND COMPILATION"
		@echo "\t─────▄▀▄─────▄▀▄"
		$(CC) $(CFLAGS) $(VALGND_FLAG) $(LIB_BINARY) $(OBJS_VALGND) -o $@
		@echo "\t[ $(GREEN)✔$(NONE) ] push_swap_valgn"

run_valgnd: push_swap_valgrind
	@echo "Executing binary with valgrind"
	@valgrind ./push_swap_valgrind $(var)

#=============================================================================#
#                                COMMANDS                                     #
#=============================================================================#

run: push_swap_prof
	@echo "Executing binary"
	./push_swap_prof $(var)

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
