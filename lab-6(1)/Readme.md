# DAA Lab-06

## Design and Analysis of Algorithms

**Course:** BTech 3rd Semester
**Branch:** CSE-B
**Lab:** DAA Lab-06
**Instructor:** Dr. Ajaya Kumar Dash
**Date:** August 31, 2026

---

## 📌 About the Lab

This lab focuses on analyzing the **time complexity** of different algorithms and implementing them using the **C programming language**.

The lab contains four major questions:

1. Operations on an unsorted array
2. Operations on square matrices
3. Convolution using Divide and Conquer
4. Sorting a permutation using reversals

---

# Q1. Operations on an Unsorted Array

Given an unsorted integer array containing `n` elements, we find the complexity of different operations.

### Operations and Worst-Case Complexity

| Operation                     | Complexity   |
| ----------------------------- | ------------ |
| Find maximum element          | `O(n)`       |
| Find first and second largest | `O(n)`       |
| Find mean                     | `O(n)`       |
| Find median                   | `O(n log n)` |
| Find standard deviation       | `O(n)`       |
| Find mode                     | `O(n²)`      |
| Remove all duplicates         | `O(n²)`      |
| Reverse the array             | `O(n)`       |
| Partition around a pivot      | `O(n)`       |

### Important Concepts

* **Maximum:** Scan the complete array once.
* **First and second largest:** Keep track of the two largest elements while scanning.
* **Mean:** Find the sum and divide by `n`.
* **Median:** Sort the array and find the middle element.
* **Standard deviation:** Calculate the mean and then process every element.
* **Mode:** Count the frequency of each element.
* **Remove duplicates:** Compare elements and remove repeated values.
* **Reverse:** Swap elements from both ends.
* **Partition:** Arrange elements according to a chosen pivot.

### Complexity

The most expensive operation in the basic implementation is generally:

`O(n²)`

---

# Q2. Operations on Square Matrices

Given two square matrices of size `n × n`, different matrix operations are performed.

### Operations and Complexity

| Operation              | Worst-Case Complexity |
| ---------------------- | --------------------- |
| Matrix Addition        | `O(n²)`               |
| Matrix Multiplication  | `O(n³)`               |
| Check Zero Matrix      | `O(n²)`               |
| Check Symmetric Matrix | `O(n²)`               |
| Determinant            | `O(n!)`               |
| In-place Transpose     | `O(n²)`               |
| Eigenvalue/Eigenvector | Algorithm dependent   |

---

## 1. Matrix Addition

Each element of one matrix is added to the corresponding element of the other matrix.

```text
C[i][j] = A[i][j] + B[i][j]
```

There are `n²` elements.

### Complexity

`O(n²)`

---

## 2. Matrix Multiplication

For every element of the result matrix, `n` multiplications/additions are required.

### Complexity

`O(n³)`

---

## 3. Zero Matrix

Check whether every element of the matrix is zero.

### Complexity

`O(n²)`

---

## 4. Symmetric Matrix

A matrix is symmetric when:

```text
A[i][j] = A[j][i]
```

### Complexity

`O(n²)`

---

## 5. Determinant

The determinant can be calculated recursively using cofactor expansion.

For the straightforward recursive implementation:

### Complexity

`O(n!)`

---

## 6. In-Place Transpose

Transpose the matrix by swapping:

```text
A[i][j] ↔ A[j][i]
```

Only one matrix is used.

### Complexity

`O(n²)`

### Extra Space

`O(1)`

---

## 7. Eigenvalues and Eigenvectors

The complexity depends on the algorithm used.

For example, iterative methods such as QR-based methods have complexity depending on the number of iterations.

---

# Q3. Convolution Using Divide and Conquer

Given two vectors:

```text
A = [a0, a1, ..., am-1]
B = [b0, b1, ..., bn-1]
```

where:

```text
n ≥ m
```

The convolution is:

```text
C[k] = Σ A[j] × B[k-j]
```

for valid values of `j`.

### Example

Consider:

```text
A = [1, 2, 3]
B = [4, 5]
```

The convolution is:

```text
C = [4, 13, 22, 15]
```

because:

```text
C[0] = 1×4 = 4

C[1] = 1×5 + 2×4
     = 5 + 8
     = 13

C[2] = 2×5 + 3×4
     = 10 + 12
     = 22

C[3] = 3×5
     = 15
```

---

## Naive Approach

The direct method uses nested loops.

### Complexity

`O(mn)`

Since `n ≥ m`, it can be considered approximately:

`O(n²)`

---

## Required Approach: FFT

To achieve the required:

`O(n log n)`

we use the **Fast Fourier Transform (FFT)**.

The process is:

```text
A → FFT → A'
B → FFT → B'

A' × B' → C'

C' → Inverse FFT → C
```

### FFT Complexity

The recurrence is:

```text
T(n) = 2T(n/2) + O(n)
```

Therefore:

```text
T(n) = O(n log n)
```

### Overall Complexity

```text
FFT(A)       → O(n log n)
FFT(B)       → O(n log n)
Multiplication → O(n)
Inverse FFT  → O(n log n)
```

Therefore:

### Final Complexity

`O(n log n)`

---

# Q4. Sorting a Permutation Using Reversals

A permutation contains numbers in some arbitrary order.

Example:

```text
4 2 5 1 3
```

The goal is to sort it:

```text
1 2 3 4 5
```

The main operation is:

```text
reverse(p, i, j)
```

which reverses the elements from position `i` to position `j`.

---

## Basic Idea

We can sort a permutation by fixing one element at a time.

For example, find the correct position of `1` and reverse the required part.

Then fix `2`, then `3`, and so on.

At most one reversal is needed to place each element.

Therefore, the number of reversals is:

`O(n)`

---

## Required Divide-and-Conquer Algorithm

To achieve the required reversal cost:

`O(n log² n)`

we use divide and conquer.

### Steps

1. Divide the values into two groups.
2. Put smaller values on the left.
3. Put larger values on the right using reversals.
4. Recursively sort the left part.
5. Recursively sort the right part.
6. Continue until the permutation is sorted.

---

## Why `O(n log² n)`?

At one level, partitioning using divide and conquer costs:

```text
O(n log n)
```

There are approximately:

```text
O(log n)
```

levels.

Therefore:

```text
O(n log n) × O(log n)
```

which gives:

### Final Cost

```text
O(n log² n)
```

---

# 🧠 Complexity Summary

| Question                  | Main Algorithm      | Complexity        |
| ------------------------- | ------------------- | ----------------- |
| Q1 - Maximum              | Linear Scan         | `O(n)`            |
| Q1 - First/Second Largest | Linear Scan         | `O(n)`            |
| Q1 - Mean                 | Linear Scan         | `O(n)`            |
| Q1 - Median               | Sorting             | `O(n log n)`      |
| Q1 - Standard Deviation   | Linear Scan         | `O(n)`            |
| Q1 - Mode                 | Nested Loops        | `O(n²)`           |
| Q1 - Remove Duplicates    | Comparison          | `O(n²)`           |
| Q1 - Reverse              | Two Pointers        | `O(n)`            |
| Q1 - Partition            | Linear Partition    | `O(n)`            |
| Q2 - Addition             | Nested Loops        | `O(n²)`           |
| Q2 - Multiplication       | Three Loops         | `O(n³)`           |
| Q2 - Zero Check           | Nested Loops        | `O(n²)`           |
| Q2 - Symmetric Check      | Nested Loops        | `O(n²)`           |
| Q2 - Determinant          | Recursion           | `O(n!)`           |
| Q2 - Transpose            | Nested Loops        | `O(n²)`           |
| Q2 - Eigenvalues          | Algorithm Dependent | Depends on method |
| Q3 - Convolution          | FFT                 | `O(n log n)`      |
| Q4 - Reversal Sorting     | Divide & Conquer    | `O(n log² n)`     |

---

# 💻 Programming Language

All programs in this lab are implemented in:

**C**

### Required Header Files

Depending on the program:

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
```

---

# ▶️ How to Compile and Run

Using GCC:

```bash
gcc filename.c -o output
```

Run:

### Windows

```bash
output.exe
```

### Linux / macOS

```bash
./output
```

---

# 📂 Suggested GitHub Structure

```text
DAA-Lab-06/
│
├── README.md
│
├── Q1.c
├── Q2.c
├── Q3.c
└── Q4.c
```

---

# 🎯 Learning Outcomes

After completing this lab, we understand:

* How to calculate worst-case time complexity.
* How to analyze array operations.
* How to analyze matrix algorithms.
* How Divide and Conquer works.
* How FFT can be used for fast convolution.
* How reversal operations can be used for sorting.
* How to derive complexity using recurrence relations.
* How to prove algorithm correctness.

---

## Conclusion

DAA Lab-06 provides practical understanding of **algorithm design, divide and conquer, recursion, complexity analysis, matrix operations, convolution, and permutation sorting**.

The main focus is not only on writing the programs but also on understanding **why an algorithm has a particular time complexity**.