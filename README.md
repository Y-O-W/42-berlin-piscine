# 42 Berlin Piscine

C exercises for the 42 Berlin piscine.

## Project layout

Each exercise gets its own directory with a Norm-compliant `Makefile`:

```
ex00/
├── Makefile
├── includes/
│   └── project.h
└── srcs/
    ├── main.c
    └── utils.c
```

42 grades one exercise at a time, so each exercise directory carries its own `Makefile` rather
than sharing one at the repo root.

## Makefile

```makefile
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
```

- `SRCS` lists just filenames; `OBJS` maps them into `objs/` via substitution — add a new `.c`
  file by adding it to `SRCS` only.
- The four targets (`all`, `clean`, `fclean`, `re`) are what Norm/the 42 grader expects to exist,
  with exactly that behavior.
- `.PHONY` stops Make from confusing target names with real files.
- **Recipe lines must be indented with a real tab character, not spaces** — Make treats that as
  syntax, not style, and fails with `missing separator` otherwise.
- Extending to `libft`: add `LIBFT_DIR = libft`, append `-L$(LIBFT_DIR) -lft` to the link line,
  and add a `make -C $(LIBFT_DIR)` step before `$(NAME)`.
