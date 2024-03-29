# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 20:16:44 by cwitting          #+#    #+#              #
#    Updated: 2019/12/06 05:40:35 by cwitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc -g -O0
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft/
SRC_DIR = ./srcs/
INC_DIR = ./includes/
FT_PRINTF_DIR = ./lft_printf/

SOURCE := 	new_lst.c args_to_lst.c pb.c pa.c swap.c ss.c rotate.c rr.c \
			rev_rotate.c rrr.c stack_is_sorted.c get_next_line.c init_args.c \
			sort_3_numbers.c read_commands.c ft_error.c args_to_array.c \
			array_is_sorted.c destroy_stacks.c sort_5_numbers.c final_sort.c \
			sort_lists_hard.c from_a_to_b.c leave_3_nbrs_in_a.c list_is_sorted.c \
			print_stacks.c spin_stack.c get_insert_index.c cases_simple_sort.c \
			get_insert_index_simpsort.c utils.c sort_2.c

INCLUDES = push_swap.h ft_printf.h get_next_line.h
SRC := $(addprefix $(SRC_DIR), $(SOURCE))
INC = $(addprefix $(INC_DIR), $(INCLUDES))
OBJ = $(SOURCE:.c=.o)

GREEN = \033[0;32m
RESET = \033[0m
RED = \033[0;31m
CYAN = \033[0;36m

all: lib $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(SRC) $(INC)
	@echo "$(GREEN)compiling...$(RESET)"
	@$(CC) -o $(CHECKER) srcs/checker.c $(SRC) -L $(LIB_DIR) -lft \
	-L $(FT_PRINTF_DIR) -lftprintf
	@echo "$(CYAN)DONE$(RESET)"

$(PUSH_SWAP): $(SRC) $(INC)
	@echo "$(GREEN)compiling...$(RESET)"
	@$(CC) -o $(PUSH_SWAP) srcs/push_swap.c $(SRC) -L $(LIB_DIR) -lft \
	-L $(FT_PRINTF_DIR) -lftprintf
	@echo "$(CYAN)DONE$(RESET)"

$(FT_PRINTF):
	@make -c $(FT_PRINTF_DIR)

lib:
	@make -C $(LIB_DIR) > /dev/null
	@make -C $(FT_PRINTF_DIR) > /dev/null

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	@rm -rf *.dSYM

fclean:	clean
	@make -C $(LIB_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	@rm -f $(CHECKER)
	@rm -f $(PUSH_SWAP)
	@echo "$(RED)Fully clean$(RESET)"

re:	fclean all

.PHONY: clean fclean
