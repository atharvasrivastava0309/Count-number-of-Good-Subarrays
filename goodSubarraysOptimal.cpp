/*
Problem: Count the Number of Good Subarrays

Description:
You're given an array `nums` and an integer `k`. You need to count how many subarrays are "good".
A subarray is considered good if there are at least `k` pairs of indices (i, j) such that:
  - i < j
  - nums[i] == nums[j]

A subarray is any contiguous non-empty segment of the array.

Example:
Input:
    nums = [3,1,4,3,2,2,4], k = 2
Output:
    4

Approach (Optimized - Sliding Window):
1. Use two pointers (`left` and `right`) to form a sliding window.
2. Maintain a frequency map of elements in the current window.
3. Keep a running count of equal pairs inside the window.
4. Expand the window using `right` until you get at least `k` equal pairs.
5. Once the condition is satisfied, all subarrays starting from current `left` to `right ... n-1` are good.
6. Shrink the window by moving `left` and update frequency and pair counts accordingly.

Time Complexity: O(n), where n is the size of the array (due to the sliding window traversal).
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

using ll = long long;

// Function to count the number of good subarrays
ll countGoodSubarrays(vector<int>& nums, ll k) {
    ll n = nums.size();
    ll goodSubarrays = 0;
    ll equalPairs = 0;
    map<int, int> freq;

    ll left = 0, right = 0;

    // Slide the window using two pointers
    while (left < n) {
        // Expand the window until at least k equal pairs are formed
        while (right < n && equalPairs < k) {
            freq[nums[right]]++;

            // If an element repeats, it contributes new pairs
            if (freq[nums[right]] > 1) {
                equalPairs += freq[nums[right]] - 1;
            }

            right++;
        }

        // If condition is met, all subarrays from [left, right] to [left, n-1] are good
        if (equalPairs >= k) {
            goodSubarrays += (n - right + 1);
        }

        // Shrink the window from the left and update pair count
        freq[nums[left]]--;
        if (freq[nums[left]] > 0) {
            equalPairs -= freq[nums[left]];
        }

        left++;
    }

    return goodSubarrays;
}

int main() {
    ll n, k;

    // Input size of array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter the elements of the array:\n";
    for (ll i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Input required number of equal pairs
    cout << "Enter the value of k (minimum number of equal pairs required): ";
    cin >> k;

    // Compute and print the result
    ll result = countGoodSubarrays(nums, k);
    cout << "Number of good subarrays: " << result << endl;

    return 0;
}
