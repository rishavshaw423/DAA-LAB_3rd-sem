# find_the_switch.c

Here's a walkthrough of what the code does:

**`find_the_switch()`**: A binary search that finds the index where an array of 0s and 1s switches from 0 to 1 (assuming the array is sorted, i.e. all 0s come before all 1s).
- Maintains `start` and `end` pointers, and a `best_guess` that tracks the earliest `1` found so far (initialized to `-1`, meaning "not found yet").
- On each iteration, checks the middle element:
  - If it's `1`, this could be the switch point, so it's recorded in `best_guess`, and the search continues in the *left* half (`end = mid - 1`) to check for an even earlier `1`.
  - If it's `0`, the switch must be somewhere to the right, so the search continues in the right half (`start = mid + 1`).
- Returns `best_guess` — the index of the first `1`, or `-1` if none was found (array is all 0s).

**`main()`**:

1. Prompts for the number of elements, `n`, and declares a variable-length array `arr[n]`.
2. Reads `n` values (expected to be 0s and 1s, sorted) into the array.
3. Calls `find_the_switch()` to locate the first `1`.
4. Prints the index if found, or a message saying the array is entirely 0s if not.

Essentially: this is a binary search variant for finding the boundary/transition point in a sorted binary array — a classic building block for problems like "find the first true in a sorted boolean array" or "find the first occurrence of a target value." It runs in O(log n) time instead of the O(n) a linear scan would need.