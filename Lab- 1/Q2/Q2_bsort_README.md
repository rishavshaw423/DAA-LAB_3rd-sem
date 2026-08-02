# bubble_sort_comparison.c

Here's a walkthrough of what the code does:

**`bubbleSortOptimized()`**: Standard bubble sort but with an early-exit flag (`swapped`) — if a full pass makes no swaps, the array is already sorted, so it breaks out early. Returns the total number of comparisons made.

**`bubbleSortStandard()`**: The plain textbook version — always runs the full `n-1` passes regardless of whether the array becomes sorted early. Also returns the comparison count.

**`generateRandomArray()`**: Fills an array with random integers between 0 and 9999.

**`copyArray()`**: Copies one array into another (used so both sort variants run on identical input).

**`main()`**:

1. **Get inputs**: Prompts for `maxSize` (largest array size to test) and `step` (how much to increase size by each round).

2. **Set up GNUplot**: Opens a pipe to `gnuplot -persistent` and sends `set` commands (title, axis labels, grid, legend), then a `plot` command with two inline data blocks (`'-'`) — one for the optimized sort's comparisons, one for the standard sort's.

3. **Run the experiment**: Loops `n` from `step` up to `maxSize` in increments of `step`. For each `n`:
   - Generates a random array
   - Makes two identical copies of it
   - Runs both sort variants on their own copy, recording comparison counts
   - Prints the results to the console
   - Frees the temporary arrays

4. **Feed data to GNUplot**: Writes the collected `(size, comparisons)` pairs for each sort variant into the pipe, each block terminated with `e` (GNUplot's inline-data end marker).

5. **Cleanup**: Closes the GNUplot pipe and frees the result arrays.

Essentially: run both bubble sort variants on the same random data at increasing sizes → count comparisons for each → plot both curves together so you can visually see how much the early-exit optimization saves (or doesn't, since worst-case random data rarely triggers an early exit).