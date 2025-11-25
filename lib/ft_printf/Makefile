# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: laveerka <laveerka@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/11/14 05:52:06 by laveerka      #+#    #+#                  #
#    Updated: 2025/11/25 15:19:33 by laveerka      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_char_string_bonus.c ft_itoa_atoi_bonus.c ft_number_bonus.c \
	ft_pointer_hex_bonus.c ft_printf_bonus.c ft_printf_utils_bonus.c

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re