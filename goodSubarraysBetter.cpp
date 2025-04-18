/*
Problem: Count the Number of Good Subarrays

Description:
Given an array of integers `nums` and an integer `k`, we need to count how many subarrays are "good".
A subarray is called good if it has **at least k pairs of indices (i, j)** such that:
- i < j
- nums[i] == nums[j]

A subarray is any contiguous non-empty sequence of elements within the array.

Approach:
1. We check every possible subarray by starting at index `i` and ending at index `j`.
2. We use a map to keep track of the frequency of elements in the current subarray.
3. For each `nums[j]`, the number of pairs it adds is equal to how many times it has already appeared.
4. We add to the total answer whenever the count of such pairs is >= k.

Note: This approach is better than the triple nested brute-force and works fine for moderate input sizes.
Time Complexity-> O(n^2)

Example:
Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function to count good subarrays
long long countGoodSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    long long goodSubarrayCount = 0;

    // Iterate over all possible starting points of subarrays
    for (int start = 0; start < n; ++start) {
        map<int, int> frequencyMap;
        long long pairCount = 0;

        // Iterate over the end of the subarray
        for (int end = start; end < n; ++end) {
            int currentNum = nums[end];

            // If currentNum appeared before, it can form 'frequencyMap[currentNum]' new pairs
            pairCount += frequencyMap[currentNum];

            // Update frequency of the current number
            frequencyMap[currentNum]++;

            // If we have enough pairs, it's a good subarray
            if (pairCount >= k) {
                goodSubarrayCount++;
            }
        }
    }

    return goodSubarrayCount;
}

int main() {
    int n, k;

    // Input array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Input value of k
    cout << "Enter the value of k (minimum number of equal pairs required): ";
    cin >> k;

    // Calculate and display result
    long long result = countGoodSubarrays(nums, k);
    cout << "Number of good subarrays: " << result << endl;

    return 0;
}
