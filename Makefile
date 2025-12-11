# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: laveerka <laveerka@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/11/25 11:15:01 by laveerka      #+#    #+#                  #
#    Updated: 2025/12/11 13:04:01 by laveerka      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./lib/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

FILES = base_case.c chunks.c chunk_sorting.c clean_exit.c determine_rank_smallest.c \
	locations_iterations.c position_length.c operations_rotate.c operations_swap_push.c \
	optimize_operations.c solve.c solve_utils.c stack_init.c \
	utils.c visualize.c

NAME = push_swap
FILES_DIR = ./mandatory
MAND_FILES = push_swap.c

BONUS_NAME = checker
BONUS_FILES_DIR = ./bonus
BONUS_FILES = checker.c

SRCS = $(addprefix $(FILES_DIR)/, $(FILES)) $(addprefix $(FILES_DIR)/, $(MAND_FILES))
BONUS_SRCS = $(addprefix $(FILES_DIR)/, $(FILES)) $(addprefix $(BONUS_FILES_DIR)/, $(BONUS_FILES))

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(LIBFT_LIB) $(FT_PRINTF_LIB) $(NAME)

bonus: $(LIBFT_LIB) $(FT_PRINTF_LIB) $(BONUS_NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	cc $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	cc $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(BONUS_NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus