# This Makefile compiles "philo", a philosophical dining problem simulation.
NAME = philo

# Compiler to use
CC = cc

# Compiler flags for warnings and error checking
CFLAGS = -Wall -Wextra -Werror -g

# Sanitizer flags for memory error detection
SANITIZE_FLAGS = -fsanitize=address -g

# Source files
SRCS = main.c parse.c utils.c routines.c time.c printer.c destroy.c

# Object files directory
OBJS_DIR = objects

# Generated object files
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Philosophers compiled OK$(RESET)"

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

sani: CFLAGS += $(SANITIZE_FLAGS)
sani: fclean all
	@echo "$(GREEN)(Added sanitize flags)$(RESET)"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(YELLOW)Removed object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed philosophers$(RESET)"

re: fclean all

.PHONY: all sani clean fclean re