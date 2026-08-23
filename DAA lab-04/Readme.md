# DAA Lab-04 — Applications of Sorting

## 📌 Overview

This lab contains six problems based on the **applications of sorting**. The main goal is to use sorting techniques to solve different problems efficiently.

**Subject:** Design and Analysis of Algorithms (DAA)
**Lab:** Lab-04
**Semester:** 3rd Semester
**Date:** August 18, 2026

---

## 📚 Questions Covered

### Q1 — Application of Sorting-I: Sorting by Colour

Given `n` pairs containing a number and a colour (`red`, `blue`, or `yellow`), the pairs are already sorted by number.

The task is to sort them by colour:

```text
Red → Blue → Yellow
```

while keeping the numbers of the same colour sorted.

**Required complexity:** `O(n)`

### Main idea

Use separate groups for the three colours and place the elements in the appropriate group while scanning the input once.

---

## Q2 — Application of Sorting-II: Pair Sum

Given two sets `S1` and `S2`, each containing `n` elements, and a number `x`, find whether there is a pair such that:

```text
element from S1 + element from S2 = x
```

**Required complexity:** `O(n log n)`

### Main idea

Sort one set and search for the required value for every element of the other set.

---

## Q3 — Application of Sorting-III: K Elements Sum

Given a set `S` of `n` integers, an integer `T`, and an integer `k`, determine whether `k` elements of `S` add up to `T`.

**Required complexity:** `O(n^(k-1) log n)`

### Main idea

Sort the elements and use searching to efficiently find the required remaining value.

---

## Q4 — Application of Sorting-IV: Maximum People at a Party

For every person, we are given:

```text
Entry time
Exit time
```

The task is to find the time when the **maximum number of people were present simultaneously**.

**Required complexity:** `O(n log n)`

### Main idea

Convert every entry into `+1` and every exit into `-1`.

Then:

1. Sort all events by time.
2. Increase the count when someone enters.
3. Decrease the count when someone exits.
4. Keep track of the maximum count and its time.

Example:

```text
Entry → +1
Exit  → -1
```

---

## Q5 — Application of Sorting-V: Merge Overlapping Intervals

Given a list of intervals, merge all intervals that overlap.

Example:

```text
Input:
(1,3)
(2,6)
(8,10)
(7,18)
```

Output:

```text
(1,6)
(7,18)
```

**Required complexity:** `O(n log n)`

### Main idea

1. Sort intervals according to their starting point.
2. Compare the current interval with the next interval.
3. If they overlap, merge them.
4. Otherwise, store the current interval and continue.

For example:

```text
(1,3) + (2,6)
      ↓
    (1,6)
```

---

## Q6 — Application of Sorting-VI: Maximum Overlapping Intervals

Given a set of intervals, find a point that lies inside the **largest number of intervals**.

Example:

```text
(10,40)
(20,60)
(50,90)
(15,70)
```

A valid answer is:

```text
Point = 50
Maximum overlapping intervals = 3
```

**Required complexity:** `O(n log n)`

### Main idea

Convert each interval into two events:

```text
Starting point → +1
Ending point   → -1
```

Then:

1. Sort all events.
2. Maintain a count.
3. Add `1` when an interval starts.
4. Subtract `1` when an interval ends.
5. Store the point where the count becomes maximum.

---

## ⏱️ Complexity Summary

| Question | Problem                               | Required Complexity |
| -------- | ------------------------------------- | ------------------- |
| Q1       | Sort items by colour                  | `O(n)`              |
| Q2       | Find pair with sum `x`                | `O(n log n)`        |
| Q3       | Find `k` elements with sum `T`        | `O(n^(k-1) log n)`  |
| Q4       | Maximum people simultaneously present | `O(n log n)`        |
| Q5       | Merge overlapping intervals           | `O(n log n)`        |
| Q6       | Maximum overlapping intervals         | `O(n log n)`        |

---

## 🛠️ Language Used

The programs are implemented in:

```text
C
```

The programs take input from the user and display the required output.

---

## 🧠 Important Concepts

This lab mainly demonstrates:

* Sorting
* Searching
* Intervals
* Event-based processing
* Counting
* Divide-and-conquer style thinking
* Time complexity analysis
* Efficient algorithm design

---

## 📂 Suggested GitHub Structure

```text
DAA-Lab-04/
│
├── Q1.c
├── Q2.c
├── Q3.c
├── Q4.c
├── Q5.c
├── Q6.c
└── README.md
```

---

## 🎯 Conclusion

DAA Lab-04 demonstrates how **sorting can be used as a basic step to solve different algorithmic problems efficiently**.

The problems cover sorting by colour, finding pairs with a required sum, finding `k` elements with a given sum, finding the maximum number of people present at a party, merging overlapping intervals, and finding the point covered by the maximum number of intervals.

All problems are designed around improving efficiency and analysing the required time complexity.
