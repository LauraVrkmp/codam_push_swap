# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: laveerka <laveerka@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/11/14 05:52:06 by laveerka      #+#    #+#                  #
#    Updated: 2025/12/14 18:08:46 by laveerka      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ../libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

NAME = libftprintf.a

SRCS = ft_char_string_bonus.c ft_itoa_atoi_bonus.c ft_number_bonus.c \
	ft_pointer_hex_bonus.c ft_printf_bonus.c ft_printf_ext_bonus.c \
	ft_printf_utils_bonus.c

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT_LIB) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re