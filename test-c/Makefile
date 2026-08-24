NAME        = my_program

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

SRCS_DIR    = srcs
OBJS_DIR    = objs
INCLUDES    = -Iincludes

SRCS        = main.c utils.c
OBJS        = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
