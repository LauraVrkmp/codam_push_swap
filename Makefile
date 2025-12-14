# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: laveerka <laveerka@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/11/25 11:15:01 by laveerka      #+#    #+#                  #
#    Updated: 2025/12/14 18:34:55 by laveerka      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

FILES = base_case.c chunks.c chunks_size.c chunk_sorting.c chunk_sorting_ext.c \
	clean_exit.c determine_rank_smallest.c locations_iterations.c \
	position_length.c operations_rotate.c operations_swap_push.c \
	optimize_operations.c solve.c solve_utils.c stack_init.c utils.c visualize.c
FILES_DIR = ./src

NAME = push_swap
MAND_FILES = push_swap.c

BONUS_NAME = checker
BONUS_FILES = checker.c

SRCS = $(addprefix $(FILES_DIR)/, $(FILES)) $(addprefix $(FILES_DIR)/, $(MAND_FILES))
BONUS_SRCS = $(addprefix $(FILES_DIR)/, $(FILES)) $(addprefix $(FILES_DIR)/, $(BONUS_FILES))

OBJS_DIR = ./objs
OBJS = $(SRCS:$(FILES_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(FILES_DIR)/%.c=$(OBJS_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(FT_PRINTF_LIB) $(NAME)

bonus: $(FT_PRINTF_LIB) $(BONUS_NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(FILES_DIR)/%.c | $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS) $(FT_PRINTF_LIB)
	cc $(CFLAGS) $(OBJS) -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

$(BONUS_NAME): $(OBJS_DIR) $(BONUS_OBJS) $(FT_PRINTF_LIB)
	cc $(CFLAGS) $(BONUS_OBJS) -L$(FT_PRINTF_DIR) -lftprintf -o $(BONUS_NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus