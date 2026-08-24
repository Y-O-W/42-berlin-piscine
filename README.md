# 42 Berlin Piscine

C exercises for the 42 Berlin piscine.

## Project layout

Each exercise gets its own directory with its own Norm-compliant `Makefile` (42 grades one
exercise at a time, so nothing is shared at the repo root):

```
ex00/
├── Makefile
├── includes/
│   └── project.h
└── srcs/
    ├── main.c
    └── utils.c
```

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

- Add a new `.c` file by adding it to `SRCS` only — `OBJS` maps it into `objs/` automatically.
- `all`, `clean`, `fclean`, `re` are the four targets Norm/the grader require.
- **Recipe lines need a real tab, not spaces** — Make fails with `missing separator` otherwise.
- `objs/` is gitignored; only source, headers, and the `Makefile` get committed.
- For `libft`: add `LIBFT_DIR = libft`, append `-L$(LIBFT_DIR) -lft` to the link line, and add a
  `make -C $(LIBFT_DIR)` step before `$(NAME)`.

## Header guard

`includes/project.h`, guard name derived from the filename:

```c
#ifndef PROJECT_H
# define PROJECT_H

# include <stddef.h>

// function prototypes go here

#endif
```

Norm requires one space after `#` per nesting level (`#ifndef` at column 0, `# define`/
`# include` indented one space).
