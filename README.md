# 42 Berlin Piscine

C exercises for the 42 Berlin piscine.

## The Norm (v4.1) — key rules

Full text: `42-berlin_norm_4.1.pdf`. Check with `norminette <file|dir>`; it prevails in
evaluations. Rules marked *(\*)* in the PDF aren't checked by norminette but a reviewer can
still fail you for them.

**Naming**
- `snake_case` only (lowercase, digits, `_`) for identifiers, files and directories.
- Prefixes: `s_` struct, `t_` typedef, `u_` union, `e_` enum, `g_` global.
- Macros are `UPPERCASE`. Standard ASCII only (except inside string/char literals).
- Non-`const`/non-`static` globals are forbidden unless the project allows them.

**Formatting**
- Functions: max **25 lines** (braces excluded), max **4 parameters**, max **5 variables**.
- Lines: max **80 columns** (a tab counts as 4). Indent with **real tabs** (width 4).
- Braces on their own line (except `struct`/`enum`/`union` declarations).
- Declarations at the top of the function, one per line, names aligned on the same column,
  then one empty line, and no other empty lines in the function body.
- `*` sticks to the variable name. No declaration + initialisation on one line (except
  globals, `static`, constants).
- One instruction per line; one space around operators and after `,`/`;`/keywords.
- No trailing whitespace, no two consecutive empty lines, no two consecutive spaces.
- `return (value);` needs parentheses; `void` is required for no-arg functions; prototype
  parameters must be named; one tab between return type and function name.

**Forbidden**: `for`, `do...while`, `switch`/`case`, `goto`, ternary `?:`, VLAs, implicit types.

**Files and headers**
- Max **5 function definitions** per `.c` file; never `#include` a `.c` file.
- Every `.c`/`.h` starts with the 42 header (login, email, creation/update dates).
- Headers: include guard (`ft_foo.h` -> `FT_FOO_H`), includes at the top, no unused includes,
  only declarations, defines, prototypes and macros. Structs cannot be declared in `.c` files.
- Preprocessor: global scope only, no multiline macros, `#define` only for literal/constant
  values, indent directives inside `#if`/`#ifdef`/`#ifndef`.

**Comments**: English, useful, never inside function bodies (own line or end of line only).

**Makefile** (not checked by norminette): `$(NAME)`, `all` (default), `clean`, `fclean`, `re`
are mandatory; must not relink needlessly; list source files explicitly (no `*.c`/`*.o`);
build any local library (e.g. `libft`) automatically.

## Editor setup

`.vscode/settings.json` applies to every exercise folder: real tabs (width 4), 80-column
ruler, trailing whitespace trimmed, final newline, LF line endings, and format-on-save off
so no formatter reflows code against the Norm. `.vscode/tasks.json` adds
*Terminal > Run Task > norminette: current file / current exercise*.

The 42 header isn't built into VS Code; install a "42 Header" extension (or use `:Stdheader`
in vim) and set your login/email.

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
