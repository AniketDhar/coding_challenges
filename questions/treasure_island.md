# Coding Challenge: Treasure Island

## Problem Statement
You are given a map represented as a 2D grid, where each cell is a part of the sea ('O'), a piece of land ('L'), or a treasure ('X'). You need to find the shortest path from the top-left corner of the grid to the treasure. You can only move up, down, left, or right. The goal is to return the minimum number of steps required to reach the treasure.

Write a function `shortestPathToTreasure` that takes the 2D grid as input and returns the length of the shortest path to the treasure. If there is no path to the treasure, return -1.

## Input
A 2D grid of size `n x m` where each cell is one of 'O', 'L', or 'X'.

## Output
An integer representing the length of the shortest path to the treasure. If there is no path, return -1.

## Constraints
- The grid will have at least one row and one column.
- The starting cell (top-left corner) will always be 'O' or 'L'.
- There will be exactly one 'X' in the grid.

## Example

**Example 1:**

```cpp
vector<vector<char>> grid = {
    {'O', 'O', 'O', 'O'},
    {'L', 'L', 'L', 'O'},
    {'O', 'L', 'O', 'X'},
    {'O', 'O', 'O', 'O'}
};

Output: 5
```

**Example 2:**

```cpp
vector<vector<char>> grid = {
    {'O', 'L', 'O'},
    {'O', 'L', 'X'},
    {'O', 'O', 'O'}
};

Output: 3
```