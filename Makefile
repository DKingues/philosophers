# Name and compiler

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g

# Sources and objects

SRCS = main.c parser.c helper.c data_start.c thread_utils.c utils.c

SRCS_DIR = srcs

OBJS_DIR = objs

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

PARSER_OBJS = $(addprefix $(OBJS_DIR)/, $(PARSER:.c=.o))

# Colors

NO_COLOR = \033[0m

COLOR_RED = \033[1;31m

COLOR_GREEN = \033[1;32m

COLOR_PURPLE = \033[1;35m

COLOR_CYAN = \033[1;36m

# Messages

COMP_START = @echo "$(NO_COLOR)\nGathering philosophers...\n"

PHILO_OK = @echo "$(COLOR_GREEN)Philosophers gathered.$(NO_COLOR)\n"

PHILO_KO = @echo "$(COLOR_RED)Philosophers left.$(NO_COLOR)\n"

CLEAN_RUN = @echo "$(NO_COLOR)\nCleaning philosophers objects...\n"

FCLEAN_RUN = @echo "$(NO_COLOR)\nCleaning philosphers objects and executables...\n"

CLEAN_DONE = @echo "$(COLOR_GREEN)Clean complete!$(NO_COLOR)\n"

# Rules

all: $(NAME)
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@$(PHILO_OK)
	
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@$(COMP_START)

clean:
	@rm -rf $(OBJS_DIR)
	@$(CLEAN_RUN)
	@$(CLEAN_DONE)
	@$(PHILO_KO)
	
fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)
	@$(FCLEAN_RUN)
	@$(CLEAN_DONE)
	@$(PHILO_KO)

re: fclean all

.PHONY: all clean fclean re

r:
	@make re && clear && ./minishell

rv:
	@make re && clear && valgrind --leak-check=full --show-leak-kinds=all  --track-fds=yes --track-origins=yes  --suppressions=readline.supp -s ./minishell

	