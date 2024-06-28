# Coding Challenge: Two Sum

## Problem Statement

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

## Example

**Example 1:**

```cpp
vector<int> nums = {2, 7, 11, 15};
int target = 9;

Output: [0, 1] (Because nums[0] + nums[1] == 9)
```

**Example 2:**

```cpp
vector<int> nums = {3, 2, 4};
int target = 6;

Output: [1, 2]
```

**Example 3:**

```cpp
vector<int> nums = {3, 3};
int target = 6;

Output: [0, 1]
```

## Constraints
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists.