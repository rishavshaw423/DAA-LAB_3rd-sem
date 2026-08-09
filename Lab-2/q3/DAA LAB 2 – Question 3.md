# DAA LAB 2 – Question 3

## Merging K Sorted Arrays

### Aim

To merge **K sorted arrays** using two different methods and compare their order of growth.

The two methods used are:

1. **Method 1:** Merge arrays one by one.
2. **Method 2:** Merge arrays pairwise.

---

## Problem

Suppose we have `k` sorted arrays, and each array contains `n` elements.

Example:

```text
A1 = 1  3  5
A2 = 2  4  6
A3 = 7  8  9
```

The objective is to merge all the sorted arrays into one sorted array.

---

# Method 1 – Sequential Merging

In Method 1, we merge the arrays **one at a time**.

The process is:

```text
A1 + A2
     ↓
Result + A3
     ↓
Result + A4
     ↓
...
     ↓
Final Result
```

### Example

For 4 arrays:

```text
A1 + A2
     ↓
R1

R1 + A3
     ↓
R2

R2 + A4
     ↓
Final Result
```

The size of the result keeps increasing after every merge.

The program represents its growth as:

```text
O(nk²)
```

The calculation used in the program is:

```c
method1Growth =
    n * (double)k * (k + 1) / 2.0;
```

---

# Method 2 – Pairwise Merging

In Method 2, arrays are merged **two at a time**.

### Round 1

```text
A1 + A2
A3 + A4
A5 + A6
...
```

### Round 2

```text
R1 + R2
R3 + R4
...
```

### Round 3

```text
R1 + R2
```

This continues until only one array remains.

The number of merging levels is approximately:

```text
log₂(k)
```

Each level processes approximately `kn` elements.

Therefore, the program represents the growth as:

```text
O(nk log₂ k)
```

The calculation used in the program is:

```c
method2Growth =
    n * k * log2(k);
```

---

# Comparison

| Method | Merging Strategy | Order of Growth |
|---|---|---|
| Method 1 | Merge one by one | O(nk²) |
| Method 2 | Merge pairwise | O(nk log₂ k) |

---

## `mergeTwoArrays()` Function

The function:

```c
mergeTwoArrays()
```

merges two already sorted arrays.

It compares the current elements of both arrays and places the smaller element into the result array.

For example:

```text
A = 1  4  7
B = 2  3  8
```

The merged result is:

```text
1  2  3  4  7  8
```

---

## Program Working

The program creates the file:

```text
q3_merge.txt
```

The file contains three columns:

```text
k Method1_O(nk^2) Method2_O(nklogk)
```

The program uses:

```text
n = 10
```

as the size of every array.

The value of `k` is varied from:

```text
2 to 100
```

For every value of `k`, the theoretical growth of both methods is calculated and stored in the file.

---

## Sample Data Format

The generated file has the following format:

```text
# k Method1_O(nk^2) Method2_O(nklogk)
2 ...
3 ...
4 ...
...
100 ...
```

The first column represents the number of sorted arrays.

The second column represents the growth of Method 1.

The third column represents the growth of Method 2.

---

## Testing the Methods

The program also creates:

```text
k = 4
n = 10
```

sample sorted arrays.

Each array is filled with sorted values and then both methods are executed once.

This verifies that both merging methods can process the sorted arrays.

---

## Compilation

Because the program uses `log2()` from the math library, compile it using:

```bash
gcc q3_merge.c -o q3_merge -lm
```

Run the program:

```bash
./q3_merge
```

On Windows:

```bash
q3_merge.exe
```

After successful execution:

```text
q3_merge.txt created successfully.
```

---

# Gnuplot

Create a file named:

```text
q3_merge.gnu
```

Use:

```gnuplot
set title "Merging K Sorted Arrays"
set xlabel "Number of Arrays (k)"
set ylabel "Order of Growth"

set grid

set terminal png
set output "q3_merge.png"

plot "q3_merge.txt" using 1:2 with linespoints title "Method 1 - O(nk^2)", \
     "q3_merge.txt" using 1:3 with linespoints title "Method 2 - O(nklogk)"
```

Run:

```bash
gnuplot q3_merge.gnu
```

This generates:

```text
q3_merge.png
```

---

## Files

```text
Q3/
│
├── q3_merge.c
├── q3_merge.txt
├── q3_merge.gnu
├── q3_merge.png
└── README.md
```

---

## Result

The program generates and plots the theoretical order of growth of the two methods for merging `k` sorted arrays.

```text
Method 1 → O(nk²)

Method 2 → O(nk log₂ k)
```

---

## Conclusion

Method 1 merges the arrays sequentially, causing the amount of work to increase as the intermediate result becomes larger.

Method 2 merges arrays pairwise in multiple levels. Since the number of levels is approximately `log₂(k)`, it has a lower order of growth:

```text
O(nk log₂ k)
```

Therefore, **Method 2 has better asymptotic growth than Method 1 as the number of sorted arrays `k` increases**.