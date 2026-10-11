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
