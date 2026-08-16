# DAA Lab-03 --- Divide and Conquer and Loop Invariants

**Course:** Design and Analysis of Algorithms (DAA)\
**Lab:** Lab-03\
**Semester:** 3rd Semester\
**Date:** August 11, 2026

## Overview

This lab contains six problems covering:

1.  Binary Search vs Ternary Search
2.  Defective Coin using Divide and Conquer
3.  Maximum and Minimum using Divide and Conquer
4.  Matrix Multiplication using Strassen's Method
5.  Special-Pattern Matrix Multiplication using Divide and Conquer
6.  Selection Sort and Loop Invariants

All programs are implemented in **C**. The programs that require
experimental validation automatically generate a `result.txt` file,
which is used by the corresponding **Gnuplot (`.gnu`)** file.

------------------------------------------------------------------------

# Question 1 --- Binary Search vs Ternary Search

## Objective

Implement Binary Search and Ternary Search on a sorted list and
experimentally justify which search is better.

## Algorithms

### Binary Search

-   Divides the search interval into two parts.
-   Time complexity: **O(log₂ n)**.

### Ternary Search

-   Divides the search interval into three parts.
-   Time complexity: **O(log₃ n)**.

## Files

-   `Q1_Binary_Ternary_Search.c`
-   `Q1_Binary_Ternary_Search.gnu`
-   `result.txt` --- generated automatically by the C program

## Run

``` bash
gcc Q1_Binary_Ternary_Search.c -o q1
./q1
gnuplot Q1_Binary_Ternary_Search.gnu
```

## Validation

The program compares the execution time of Binary Search and Ternary
Search for increasing input sizes.

------------------------------------------------------------------------

# Question 2 --- Search the Defective Coin

## Objective

Find a possible lighter defective coin, or report that none is lighter,
using a divide-and-conquer approach with logarithmic complexity.

## Approach

The coins are divided into groups and a balance scale is used to
determine which part can contain the lighter coin.

The algorithm repeatedly reduces the possible search space.

## Complexity

The required complexity is:

**O(log₂ n)**

or more specifically:

**log₂ n + c**

for some constant `c`.

## Files

-   `Q2_Defective_Coin.c`
-   `Q2_Defective_Coin.gnu`
-   `result.txt` --- generated automatically

## Run

``` bash
gcc Q2_Defective_Coin.c -o q2
./q2
gnuplot Q2_Defective_Coin.gnu
```

## Validation

The program records the number of balance weighings for increasing
values of `n` and plots the result.

------------------------------------------------------------------------

# Question 3 --- Maximum and Minimum using Divide and Conquer

## Objective

Find both the maximum and minimum elements of an array using the Divide
and Conquer approach.

## Approach

The array is recursively divided into two halves.

For each half:

-   Find its minimum.
-   Find its maximum.

Then combine the results from the two halves.

## Complexity

The number of comparisons is bounded by approximately:

**3n/2 − 2**

for even `n`.

The overall running time is:

**O(n)**

## Files

-   `Q3_Max_Min_Divide_Conquer.c`
-   `Q3_Max_Min_Divide_Conquer.gnu`
-   `result.txt` --- generated automatically

## Run

``` bash
gcc Q3_Max_Min_Divide_Conquer.c -o q3
./q3
gnuplot Q3_Max_Min_Divide_Conquer.gnu
```

## Validation

The program compares the actual number of comparisons with the
theoretical comparison bound.

------------------------------------------------------------------------

# Question 4 --- Matrix Multiplication using Strassen's Method

## Objective

Multiply two square matrices of size `n × n` using Strassen's Divide and
Conquer method.

## Approach

Strassen's method divides each matrix into four submatrices and reduces
the number of recursive matrix multiplications from eight to seven.

The seven products are combined to obtain the four blocks of the
resulting matrix.

## Recurrence

``` text
T(n) = 7T(n/2) + O(n²)
```

Therefore:

``` text
T(n) = O(n^log₂7)
```

which is approximately:

``` text
O(n^2.807)
```

## Files

-   `Q4_Strassen_Matrix_Multiplication.c`
-   `Q4_Strassen_Matrix_Multiplication.gnu`
-   `result.txt` --- generated automatically

## Run

``` bash
gcc Q4_Strassen_Matrix_Multiplication.c -o q4
./q4
gnuplot Q4_Strassen_Matrix_Multiplication.gnu
```

## Validation

The program measures execution time for increasing square matrix sizes
and plots the result.

------------------------------------------------------------------------

# Question 5 --- Special-Pattern Matrix Multiplication

## Objective

Multiply two `n × n` matrices where:

``` text
n = 2^k
```

and each matrix has the recursive structure:

``` text
        [ M1  M2 ]
M   =   [ M2  M1 ]
```

Each block recursively has the same structure until single integer
elements are reached.

## Approach

The divide-and-conquer algorithm exploits the repeated diagonal and
off-diagonal blocks instead of treating all four blocks as independent
matrices.

The result also preserves the same special structure:

``` text
        [ X  Y ]
M1*M2 = [ Y  X ]
```

where:

``` text
X = AC + BD
Y = AD + BC
```

## Complexity

The required complexity is:

**O(n²)**

## Files

-   `Q5_Special_Pattern_Matrix_Corrected.c`
-   `Q5_Special_Pattern_Matrix_Corrected.gnu`
-   `result.txt` --- generated automatically

## Run

``` bash
gcc Q5_Special_Pattern_Matrix_Corrected.c -o q5
./q5
gnuplot Q5_Special_Pattern_Matrix_Corrected.gnu
```

## Validation

The program records the number of scalar multiplications and compares it
with the theoretical `n²` growth.

A log-log plot is used to make the quadratic growth visible.

------------------------------------------------------------------------

# Question 6 --- Selection Sort using Loop Invariants

## Objective

Use a loop invariant to prove the correctness of Selection Sort.

The proof must contain:

1.  Initialization
2.  Maintenance
3.  Termination

## Loop Invariant

At the beginning of iteration `i`, the portion:

``` text
A[0 ... i-1]
```

contains the `i` smallest elements in sorted order.

### Initialization

Before the first iteration, `i = 0`.

Therefore the sorted portion is empty, so the invariant is true.

### Maintenance

During iteration `i`, Selection Sort finds the smallest element in:

``` text
A[i ... n-1]
```

and places it at `A[i]`.

Therefore:

``` text
A[0 ... i]
```

is sorted and contains the smallest `i + 1` elements.

### Termination

After `n-1` iterations,:

``` text
A[0 ... n-2]
```

is sorted.

The final element must therefore also be in its correct position.

## Complexity

Selection Sort performs:

``` text
(n-1) + (n-2) + ... + 1
```

comparisons.

Therefore:

``` text
n(n-1)/2
```

comparisons are performed.

Thus:

-   Best case: **Θ(n²)**
-   Worst case: **Θ(n²)**

The best case is not asymptotically faster because Selection Sort still
searches for the minimum in every remaining portion of the array.

## Files

-   `Q6_Selection_Sort_Loop_Invariant.c`
-   `Q6_Selection_Sort_Loop_Invariant.gnu`
-   `result.txt` --- generated automatically

## Run

``` bash
gcc Q6_Selection_Sort_Loop_Invariant.c -o q6
./q6
gnuplot Q6_Selection_Sort_Loop_Invariant.gnu
```

## Validation

The program tests both:

-   Already sorted input --- best case
-   Reverse sorted input --- worst case

and compares their number of comparisons with:

``` text
n(n-1)/2
```

------------------------------------------------------------------------

# General Requirements

## Software

-   C compiler such as GCC
-   GNUplot

## General Workflow

For each question:

``` text
1. Compile the C program
2. Run the C program
3. result.txt is generated automatically
4. Run the corresponding .gnu file
5. Observe the graph / experimental result
```

Example:

``` bash
gcc Q1_Binary_Ternary_Search.c -o q1
./q1
gnuplot Q1_Binary_Ternary_Search.gnu
```

## Important

The `result.txt` files do **not** need to be created manually. They are
generated by the C programs.

------------------------------------------------------------------------

# Conclusion

This lab demonstrates several important algorithm-analysis concepts:

-   Searching with different divide-and-conquer strategies
-   Logarithmic divide-and-conquer algorithms
-   Linear-time divide-and-conquer algorithms
-   Strassen's faster matrix multiplication
-   Exploiting special matrix structure
-   Experimental complexity validation
-   Loop invariants for proving sorting correctness