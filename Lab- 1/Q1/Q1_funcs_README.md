# functions.c

Here's a walkthrough of what the code does:

**Structure**: Defines a `Function` struct holding a name and a computed `double` value.

**`compare()`**: A comparator for `qsort()` — sorts `Function` structs by their `value` field in ascending order.

**`main()`**:

1. **Get n, compute values**: Prompts for `n`, then builds an array of 12 `Function` structs, each computing a different growth function (`1/n`, `log2(n)`, `12√n`, `n²`, `2^n`-scale things, `3^n`, etc.) at that `n`.

2. **Sort and print**: Calls `qsort()` on the array using `compare()`, then prints the function names in increasing order of their computed value, joined with `<`.

3. **Get maxN, write data file**: Prompts for a max `n`, then loops `i` from 1 to `maxN`, computing all 12 functions again for each `i` and writing them as rows to `functions.dat` (columns: `i`, then each function's value). Special-cases `i == 1` for `log2` and `n·log2(n)` to avoid `0`/undefined values.

4. **Plot with GNUplot**: Opens a pipe to `gnuplot -persistent` via `popen()`, sends `set` commands (title, log-scale y-axis, grid, legend), then a single `plot` command referencing `functions.dat` with a different column per function, each as its own colored line.

5. Closes the pipe and exits.

Essentially: compute → sort/print for one `n` → generate a table across a range of `n` → hand that table to GNUplot to visualize growth rates on a log scale.