# DAA LAB 2 – Question 2

## Merge Sort and Modified Merge Sort

### Aim

To compare the order of growth of **Ordinary Merge Sort** and **Modified Merge Sort**, where the modified version divides the array into three parts.

---

## Problem

The program generates the theoretical order of growth for:

1. Ordinary Merge Sort
2. Modified Merge Sort

The generated values are stored in:

```text
merge_sort.txt
```

These values can then be plotted using Gnuplot.

---

## 1. Ordinary Merge Sort

Ordinary Merge Sort divides the array into **two parts**.

Its recurrence relation is:

```text
T(n) = 2T(n/2) + O(n)
```

Therefore, its time complexity is:

```text
O(n log₂ n)
```

The program calculates the growth using:

```c
mergeSort = n * log2(n);
```

For `n = 1`, the value is taken as:

```text
1
```

---

## 2. Modified Merge Sort

The modified Merge Sort divides the array into **three parts**.

Each of the three parts is recursively sorted, and then the three sorted parts are merged.

The recurrence relation is:

```text
T(n) = 3T(n/3) + O(n)
```

Therefore, its time complexity is:

```text
O(n log₃ n)
```

The program calculates:

```text
log₃(n) = log₂(n) / log₂(3)
```

Therefore, the growth is calculated as:

```c
modifiedMergeSort = n * (log2(n) / log2(3));
```

For `n = 1`, the value is taken as:

```text
1
```

---

## Comparison

| Algorithm | Recurrence | Order of Growth |
|---|---|---|
| Ordinary Merge Sort | `T(n) = 2T(n/2) + O(n)` | `O(n log₂ n)` |
| Modified Merge Sort | `T(n) = 3T(n/3) + O(n)` | `O(n log₃ n)` |

---

## Program Working

The program creates a file:

```text
merge_sort.txt
```

It writes the following columns:

```text
n MergeSort ModifiedMergeSort
```

Then, for every value of `n` from `1` to `1000`, it calculates the theoretical growth of both algorithms.

The generated file has the format:

```text
# n MergeSort ModifiedMergeSort
1 1.0000 1.0000
2 ...
3 ...
...
1000 ...
```

---

## Compilation

Compile the program using:

```bash
gcc merge_sort.c -o merge_sort -lm
```

The `-lm` option is required because the program uses mathematical functions such as:

```c
log2()
```

Run the program:

```bash
./merge_sort
```

On Windows:

```bash
merge_sort.exe
```

After execution, the following file will be created:

```text
merge_sort.txt
```

---

## Gnuplot

Create a file named:

```text
merge_sort.gnu
```

Use the following Gnuplot script:

```gnuplot
set title "Merge Sort vs Modified Merge Sort"
set xlabel "Input Size (n)"
set ylabel "Order of Growth"

set grid

set terminal png
set output "merge_sort.png"

plot "merge_sort.txt" using 1:2 with linespoints title "Merge Sort", \
     "merge_sort.txt" using 1:3 with linespoints title "Modified Merge Sort"
```

Run:

```bash
gnuplot merge_sort.gnu
```

This generates:

```text
merge_sort.png
```

---

## Files

```text
Q2/
│
├── merge_sort.c
├── merge_sort.txt
├── merge_sort.gnu
├── merge_sort.png
└── README.md
```

---

## Result

The program generates and plots the theoretical order of growth of Ordinary Merge Sort and Modified Merge Sort.

The two growth functions are:

```text
Ordinary Merge Sort
O(n log₂ n)

Modified Merge Sort
O(n log₃ n)
```

---

## Conclusion

Both algorithms have **n log n type growth**, but they use different logarithm bases because they divide the problem into different numbers of parts.

Ordinary Merge Sort divides the array into **2 parts**, while Modified Merge Sort divides it into **3 parts**.