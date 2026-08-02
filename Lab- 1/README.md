# C Programming Assignment — README

This repository contains 6 C programs exploring algorithm analysis, recursion, searching, sorting, and simulation, most of which use **GNUplot** to visualize results.

## Requirements

- A C compiler (GCC recommended), with `-lm` for math functions where needed
- **[GNUplot](http://www.gnuplot.org/)** installed and available on your `PATH` (required for all programs except `find_the_switch.c` and `duplicate_finder.c`)


---

## Programs

### 1. `functions.c` — Function Growth Rate Comparator
Sorts common algorithmic growth functions (`log2(n)`, `n²`, `2^n`, `3^n`, etc.) by their value at a given `n`, then plots all of them on a log-scale graph to visualize their asymptotic growth as `n` increases.

### 2. `bubble_sort_comparison.c` — Bubble Sort: Optimized vs. Standard
Compares the number of comparisons made by a standard bubble sort against an early-exit optimized version on identical random arrays, and plots comparison counts against array size.

### 3. `coin_toss_simulation.c` — Fair vs. Biased Coin Convergence
Simulates a fair coin and a biased coin toss-by-toss, tracking the running probability of heads for each, and plots their convergence toward expected values to illustrate the Law of Large Numbers.

### 4. `tower_of_hanoi.c` — Tower of Hanoi Move Count
Recursively solves the Tower of Hanoi puzzle for increasing disk counts and plots the total number of moves required, demonstrating exponential (`2^n - 1`) growth.

### 5. `find_the_switch.c` — Binary Search for the 0-to-1 Transition
Uses binary search to find the index where a sorted array of 0s and 1s switches from 0 to 1, in O(log n) time.

### 6. `duplicate_finder.c` — Duplicate Detection via Bucket Array
Generates a random array of bounded integers and detects duplicate values in O(n) time using a bucket/lookup array.

---

## Summary Table

| # | Program | Core Concept | Time Complexity |
|---|---------|---------------|------------------|
| 1 | `functions.c` | Asymptotic growth comparison & plotting | O(n log n) for sort |
| 2 | `bubble_sort_comparison.c` | Bubble sort optimization comparison | O(n²) worst case |
| 3 | `coin_toss_simulation.c` | Law of Large Numbers | O(n) |
| 4 | `tower_of_hanoi.c` | Recursion & exponential growth | O(2^n) |
| 5 | `find_the_switch.c` | Binary search on sorted binary array | O(log n) |
| 6 | `duplicate_finder.c` | Bucket-based duplicate detection | O(n) |