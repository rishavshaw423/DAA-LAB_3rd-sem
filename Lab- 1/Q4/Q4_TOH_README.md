# tower_of_hanoi.c

Here's a walkthrough of what the code does:

**`TOH()`**: The recursive Tower of Hanoi solver, using three "pegs" labeled `L` (Left/source), `R` (Right/destination), and `M` (Middle/auxiliary). For `n` disks:
- Base case (`n == 1`): just move the single disk, increment `moveCount`, and return.
- Otherwise: recursively move the top `n-1` disks from `L` to `M`, move the remaining largest disk (`L` to `R`, counted directly), then recursively move the `n-1` disks from `M` to `R`.
- `moveCount` is a global variable that accumulates the total number of moves made during a call.

**`main()`**:

1. **Get input**: Prompts for `d`, the maximum number of disks to simulate.

2. **Set up GNUplot**: Opens a pipe to `gnuplot -persistent` and sends `set` commands (title, axis labels, grid), then a `plot` command reading from an inline data block (`'-'`).

3. **Run the simulation**: Loops `n` from `1` to `d`. For each `n`:
   - Resets `moveCount` to 0
   - Calls `TOH(n, 'L', 'R', 'M')` to solve the puzzle for that many disks
   - Writes the pair `(n, moveCount)` into the GNUplot pipe

4. **Finish the plot**: Sends `e` to mark the end of the inline data block, then closes the pipe.

Essentially: this solves Tower of Hanoi for every disk count from 1 up to `d`, counts how many moves each solution takes, and plots moves vs. number of disks — which visually confirms the well-known result that the move count grows as `2^n - 1`, i.e. exponentially.