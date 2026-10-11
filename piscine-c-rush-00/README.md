# Piscine C - Rush 00

`rush(x, y)` prints a rectangle of width `x` and height `y` using only `write`
(through `ft_putchar`). Rush00 style: corners `o`, top/bottom edges `-`,
left/right edges `|`, interior spaces.

```
$> rush(5, 3)        $> rush(1, 5)
o---o                o
|   |                |
o---o                |
                     |
                     o
```

## Files

| File           | Content                                                    |
| -------------- | ---------------------------------------------------------- |
| `ft_putchar.c` | `ft_putchar` only (required by the subject), uses `write`  |
| `rush00.c`     | `rush` and its static helper `ft_print_cell`               |
| `main.c`       | Test `main`, replaced by the evaluators during the defense |

## Compile, run, test

All three files are compiled together:

```sh
cc -Wall -Wextra -Werror main.c rush00.c ft_putchar.c -o test_program
./test_program
```

Without `-o` the binary is `a.out`, as in the subject. `test_program` is in `.gitignore`.

Check the Norm:

```sh
norminette main.c rush00.c ft_putchar.c
```

To test other sizes, edit the calls in `main.c`, for example:

```c
rush(5, 3);
ft_putchar('\n');
rush(123, 42);
```

Expected results:

| Call           | Output                                    |
| -------------- | ----------------------------------------- |
| `rush(5, 3)`   | `o---o` / `\|   \|` / `o---o`             |
| `rush(5, 1)`   | `o---o`                                   |
| `rush(1, 1)`   | `o`                                       |
| `rush(1, 5)`   | `o` / `\|` x3 / `o`                       |
| `rush(4, 4)`   | `o--o` / `\|  \|` x2 / `o--o`             |
| `rush(0, 3)`, `rush(3, 0)`, `rush(-2, -2)` | nothing, no crash |

## Plan and design

**1. Describe each cell by its position, not by the rectangle's size.**
Rows run `0..y-1` and columns `0..x-1`. A cell is on an edge row if
`row == 0 || row == y - 1`, and on an edge column if `col == 0 || col == x - 1`.

| Edge row | Edge column | Character |
| -------- | ----------- | --------- |
| yes      | yes         | `o`       |
| yes      | no          | `-`       |
| no       | yes         | `\|`      |
| no       | no          | space     |

The corner case is checked first in an `if / else if / else` chain, so the other
branches never need to say "but not a corner".

**2. Two nested loops.** The outer loop walks the rows, the inner loop walks the
columns, and `'\n'` is printed after each row. `x` and `y` are never modified,
because the edge checks need them for the whole run. `row` and `col` are the
counters. `col` is reset to `0` at the start of every row.

**3. Guard clause for invalid input.**
`if (x <= 0 || y <= 0) return ;` at the top of `rush`. An empty rectangle prints
nothing. Without the guard `rush(0, 3)` printed three blank lines (the loop over
rows still ran and printed `'\n'`), while `rush(3, 0)` printed nothing. The guard
makes both consistent, and the loops cannot run forever because every loop
counter increases towards a bound.

**4. Helper function to satisfy the Norm.**
The first version had everything in `rush` and was 26 lines (limit: 25).
The choice of character moved into `static void ft_print_cell(int x, int y,
int row, int col)`:
- it takes the 4 parameters the Norm allows and has no outside state,
- `static` keeps it private to `rush00.c`, so the other rushes can use the same name,
- `rush` is left with the guard, the loops and one call per cell.

## Decisions to explain in the defense

- **Behaviour for `x <= 0` or `y <= 0`:** print nothing and return (subject allows
  free choice). Chosen because it is simple, consistent and explainable.
- **Single-row / single-column cases need no special code.** With `x == 1`, column 0
  is also the last column, so the "first **or** last" check covers it
  (`rush(1, 1)` prints a single `o`).
- **`&&` / `||` are parenthesised.** `&&` binds tighter than `||`, so
  `(row == 0 || row == y - 1) && (...)` needs the parentheses. Last row is
  `y - 1`, not `y`, because counting starts at 0.
- **Prototypes.** Each `.c` file is compiled separately, so `main.c` declares `rush`
  and `rush00.c` declares `ft_putchar`. The linker then joins the calls to the
  definitions, which is why all three files must be compiled together.
- **Parameters are copies (pass by value).** Changing `x` or `y` inside `rush`
  would not affect `main`, but it would destroy the size the edge checks use.
- **Norm:** `norminette` reports `OK!` for all three files (25-line limit, declarations
  first, one blank line after them, tabs, no `for`).

## Defense checklist

- [ ] `cc -Wall -Wextra -Werror main.c rush00.c ft_putchar.c` compiles without warnings
- [ ] The five subject examples match exactly
- [ ] `rush(123, 42)` draws correctly (no crash)
- [ ] `rush(0, y)`, `rush(x, 0)` and negative values print nothing and return
- [ ] `ft_putchar.c` contains only `ft_putchar`
- [ ] `norminette` is `OK!`
- [ ] No binary (`test_program`, `a.out`) committed

---

# Rush01

Same rectangle and the same `rush(x, y)` prototype as Rush00, but the four corners
differ and the edges are `*`.

```
$> rush(5, 3)        $> rush(1, 5)
/***\                /
*   *                *
\***/                *
                     *
                     \
```

## Files

`rush01.c` replaces `rush00.c`. `main.c` and `ft_putchar.c` are unchanged.
Both rush files define `rush`, so compile **one rush file at a time**:

```sh
cc -Wall -Wextra -Werror main.c rush01.c ft_putchar.c -o test_program
./test_program
norminette rush01.c
```

Expected results:

| Call           | Output                                   |
| -------------- | ---------------------------------------- |
| `rush(5, 3)`   | `/***\` / `*   *` / `\***/`              |
| `rush(5, 1)`   | `/***\`                                  |
| `rush(1, 1)`   | `/`                                      |
| `rush(1, 5)`   | `/` / `*` x3 / `\`                       |
| `rush(4, 4)`   | `/**\` / `*  *` x2 / `\**/`              |
| `rush(0, 3)`, `rush(3, 0)`, `rush(-2, -2)` | nothing, no crash |

## Plan and design

**1. Corner table.** A corner is the intersection of an edge row and an edge column,
so each one needs `&&`.

| Position                                | Character |
| --------------------------------------- | --------- |
| top-left (row 0, col 0)                 | `/`       |
| top-right (row 0, col `x - 1`)          | `\`       |
| bottom-left (row `y - 1`, col 0)        | `\`       |
| bottom-right (row `y - 1`, col `x - 1`) | `/`       |
| other edge cells (union: `\|\|`)        | `*`       |
| interior                                | space     |

**2. Priority order decides the degenerate cases.** The corners are tested top before
bottom and left before right, and the first match wins. This produces the subject's
asymmetric results without special cases:
- `rush(5, 1)` -> `/***\` (the top corners win over the bottom ones),
- `rush(1, 5)` -> `/` on top and `\` at the bottom,
- `rush(1, 1)` -> `/` (one cell counts as top-left).

**3. Three functions, one question each.**
- `rush`: guard (`x <= 0 || y <= 0` returns), two nested loops, newline after each
  row. Unchanged from Rush00.
- `static ft_print_cell`: classifies the cell (corner, edge or interior). A corner
  calls the corner helper, an edge prints `*`, the interior prints a space.
- `static ft_print_cell_corner`: picks `/` or `\` with four flags. Splitting it out
  keeps every function within the Norm (25 lines, 4 parameters, 5 variables).

## Decisions to explain in the defense

- **Backslash:** `'\\'` is one `char` (value 92). A single `'\'` would start an escape
  sequence and not compile.
- **Operators:** the four corner flags use `&&`. A first version used `||` (every edge
  cell became `/`), and another used commas, which compiled to an unused comparison
  that `-Werror` rejected. `!=` joined with `||` is always true, so edge flags use
  `==` with `||`.
- **Invalid sizes:** same behaviour as Rush00 (prints nothing), because of the guard.
- **Result:** `norminette` is `OK!`, builds without warnings, and the five subject
  examples plus `rush(123, 42)` match.

## Defense checklist (Rush01)

- [ ] `cc -Wall -Wextra -Werror main.c rush01.c ft_putchar.c` compiles without warnings
- [ ] The five Rush01 examples match exactly
- [ ] `rush(123, 42)` draws correctly
- [ ] Zero and negative sizes print nothing
- [ ] `norminette rush01.c` is `OK!`
- [ ] Only one rush file is compiled at a time

---

# Bonus: `main_bonus.c`

An enhanced `main` that takes the two `rush` parameters from the command line.
`atoi` from `<stdlib.h>` is allowed for this bonus only.

```sh
cc -Wall -Wextra -Werror main_bonus.c rush00.c ft_putchar.c -o test_program
./test_program 5 3
```

Use `main_bonus.c` **instead of** `main.c` (both define `main`), and one rush file
at a time (`rush00.c` or `rush01.c`).

## Behaviour

| Input                                        | Result                                    |
| -------------------------------------------- | ----------------------------------------- |
| `5 3`, `+4 3`, `007 1`, `+000006 2`          | draws the rectangle, exit `0`             |
| `0 3`, `-3 3`, `+4 -2`, `999999 0`           | valid, `rush` prints nothing, exit `0`    |
| no args, `5`, `5 3 1`                        | `Error`, exit `1`                         |
| `abc 3`, `5 x`, `5- 3`, `- 3`, `+ 3`        | `Error`, exit `1`                         |
| `1234567 3` (more than 6 digits)             | `Error`, exit `1`                         |

## Design

- `ft_valid(char *s)`: optional `-` or `+`, then 1 to 6 digits, then the end of the
  string. Returns 1 or 0.
- `ft_error()`: prints `Error` and a newline with `ft_putchar`, one character at a time.
- `main`: if `argc != 3` or either argument is invalid, print the error and
  `return (1)`. Otherwise `rush(atoi(argv[1]), atoi(argv[2]))`.

## Decisions to explain in the defense

- **Validate before converting.** `atoi` returns `0` for both `"0"` and `"abc"`, and has
  undefined behaviour on overflow. Checking the string first (digits only, at most 6)
  removes both problems, so the stdlib `atoi` is safe to use.
- **Signs are accepted.** `-` and `+` are valid, but a sign alone is not (at least one
  digit is required). Zero and negative sizes are valid input and print nothing,
  consistent with the guard in `rush`.
- **Limitation.** 6 digits protect against overflow, not against huge output
  (`999999 999999` would print a very large amount). That is a deliberate trade-off.
- **Error output** uses `ft_putchar`, so it goes to stdout. Writing to fd 2 with `write`
  would be stricter.
- `norminette main_bonus.c` is `OK!`.
