/*
Problem: Count the Number of Good Subarrays

A subarray is a contiguous part of an array. A subarray is considered "good" if it has at least 'k' pairs of indices (i, j) such that:
- i < j
- nums[i] == nums[j]

Given an array of integers `nums` and an integer `k`, we need to count how many such good subarrays exist.

Example:
Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4

Approach:
We use a brute-force method: O(n^3)
1. Iterate over all possible subarrays using two loops.
2. For each subarray, count the number of (i, j) pairs such that nums[i] == nums[j].
3. If the number of such pairs is >= k, count it as a good subarray.
Note: This method has a high time complexity and is not optimized for large arrays.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count good subarrays
long long countGoodSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    long long goodSubarrayCount = 0;

    // Try every possible subarray
    for (int start = 0; start < n; ++start) {
        unordered_map<int, int> freqMap;  // Frequency map for current subarray
        long long pairCount = 0;

        for (int end = start; end < n; ++end) {
            int num = nums[end];
            
            // If num already appeared, it can form freqMap[num] new pairs
            pairCount += freqMap[num];
            freqMap[num]++;

            // If we have enough pairs, count this subarray as good
            if (pairCount >= k) {
                goodSubarrayCount += (n - end); // all extensions of this subarray will also be good
                break;  // no need to check longer subarrays from same start
            }
        }
    }

    return goodSubarrayCount;
}

int main() {
    int n, k;

    // Input array size and k
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    // Calculate and print the number of good subarrays
    long long result = countGoodSubarrays(nums, k);
    cout << "Number of good subarrays: " << result << endl;

    return 0;
}
