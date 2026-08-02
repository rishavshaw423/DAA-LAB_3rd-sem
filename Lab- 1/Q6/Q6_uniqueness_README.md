# duplicate_finder.c

Here's a walkthrough of what the code does:

**`main()`**:

1. **Get inputs**: Prompts for `n` (how many random numbers to generate) and `range` (the upper bound — numbers are generated in `[0, range)`).

2. **Allocate arrays**:
   - `arr`: holds the `n` generated numbers.
   - `seen`: a "tracker" array of size `range`, used like a hash/lookup table where `seen[value]` records whether that value has been encountered — `0` = not seen, `1` = seen once, `2` = seen and already reported as a duplicate.

3. **Generate numbers**: Fills `arr` with `n` random values between `0` and `range - 1`, then prints them.

4. **Find duplicates**: Loops through `arr` once. For each number:
   - If `seen[value] == 1` (already encountered before), it's a duplicate — print it, mark `found = 1`, and bump `seen[value]` to `2` so the same duplicate value doesn't get printed again if it appears a third, fourth time, etc.
   - If `seen[value] == 0` (first time seeing it), just mark it as `1`.

5. **Print results**: If no duplicates were found, prints "None" and "All elements are unique." Otherwise, lists each duplicate value once and confirms duplicates were found.

6. **Cleanup**: Frees both allocated arrays.

Essentially: this is a counting/bucket approach to duplicate detection. Because it uses `seen[value]` as a direct index (only possible since values are bounded by `range`), it finds duplicates in O(n) time instead of the O(n²) a naive nested-loop comparison would need — trading a bit of memory (the `seen` array) for speed.