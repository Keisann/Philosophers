NAME = philo

OBJ_DIR = obj
SRC_DIR = .
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = philosophers.c \
		ft_atol.c \
		ft_check_args.c \
		ft_error.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)/includes

RESET = \033[0m
GREEN = \033[0;32m
BOLD = \033[1m
RED = \033[0;31m
BLUE = \033[0;34m

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)$(BOLD)✔ Programme Philo compilé avec succès !$(RESET)"
	@echo

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@echo "$(BLUE)🧹 Fichiers objets supprimés."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@echo "$(RED)🗑️  Exécutable Philo supprimé.$(RESET)"
	@echo

re: fclean all

.PHONY: all clean fclean re

