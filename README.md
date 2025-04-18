# 📊 Count the Number of Good Subarrays - C++ Solutions

This repository contains three different C++ solutions to the **"Count the Number of Good Subarrays"** problem from LeetCode.

> A subarray is considered **good** if it has at least `k` pairs of indices `(i, j)` where `i < j` and `nums[i] == nums[j]`.

---

## 🧠 Problem Statement

Given an integer array `nums` and an integer `k`, return the number of **good subarrays** of `nums`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

### 🧾 Constraints
- `1 <= nums.length <= 10^5`
- `1 <= nums[i], k <= 10^9`

---

## 🧪 Example

### Input:
```cpp
nums = [3,1,4,3,2,2,4], k = 2
```

### Output:
```cpp
4
```

### Explanation:
The following subarrays have at least 2 equal pairs:
- [3,1,4,3,2,2]
- [3,1,4,3,2,2,4]
- [1,4,3,2,2,4]
- [4,3,2,2,4]

---

## 🚀 Approaches

### 1. 🔁 Brute Force (3 Loops) 
- Checks all subarrays using triple nested loops.
- For each subarray, counts pairs using a nested loop.
- **Time Complexity**: O(n³)
- ⚠️ Not suitable for large inputs.

---

### 2. 🗂️ Frequency Map (2 Loops) 
- Uses a frequency map to count equal pairs in a subarray.
- Reduces one loop by using a hashmap for tracking duplicates.
- **Time Complexity**: O(n²)
- Works for moderately sized arrays.

---

### 3. 🚀 Sliding Window (Optimized)  
- Uses a sliding window with a frequency map.
- Counts valid subarrays in O(n) time by expanding/shrinking the window.
- **Time Complexity**: O(n)
- ✅ Efficient and scalable.

---

## 🧠 Learnings

- How to use brute force, frequency maps, and sliding window techniques for subarray problems.
- Optimizing nested loops with hashmap and window contraction.
- Applying combinatorics to count duplicate pairs.
