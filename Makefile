# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: laveerka <laveerka@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/11/25 11:15:01 by laveerka      #+#    #+#                  #
#    Updated: 2025/12/09 11:06:42 by laveerka      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./lib/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

PUSH_SWAP_DIR = ./mandatory
NAME = push_swap
FILES = base_case.c chunks.c chunk_sorting.c clean_exit.c determine_rank.c \
	locations_iterations.c position_operations.c operations_rotate.c operations_swap_push.c \
	optimize_operations.c push_swap.c solve.c solve_utils.c stack_init.c \
	utils.c visualize.c

SRCS = $(addprefix $(PUSH_SWAP_DIR)/, $(FILES))

OBJS_DIR = objs
OBJS = $(SRCS:$(PUSH_SWAP_DIR)/%.c=$(OBJS_DIR)/%.o)

CFLAGS = #-Wall -Wextra -Werror -g

all: $(LIBFT_LIB) $(FT_PRINTF_LIB) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(PUSH_SWAP_DIR)/%.c | $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	cc $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re