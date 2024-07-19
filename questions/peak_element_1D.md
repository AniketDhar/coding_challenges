# Coding Challenge: Peak Element in an Array

## Problem Statement
A peak element is an element that is greater than its neighbors. Given an array of integers, find a peak element. The array may contain multiple peaks; in that case, return the index of any one of the peaks.

## Example

```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

```
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```

## Constraints
- 1 <= nums.length <= 1000
- -2^31 <= nums[i] <= 2^31 - 1
- nums[i] != nums[i + 1] for all valid i.

## Follow-up
Your solution should be in O(log n) time complexity.