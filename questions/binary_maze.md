# Coding Challenge: Shortest Path in a Binary Maze

## Problem Statement
You are given a binary maze, where '1' represents an open cell and '0' represents a blocked cell. Your task is to find the shortest path from the top-left corner to the bottom-right corner of the maze. You can only move horizontally or vertically.

Write a function `shortestPathBinaryMaze` that takes a 2D grid representing the binary maze and returns the length of the shortest path from the top-left corner to the bottom-right corner. If there is no path, return -1.

## Input
A 2D array `grid` of size `n x m` where `grid[i][j]` is either 0 or 1.

## Output
An integer representing the length of the shortest path from the top-left corner to the bottom-right corner. If there is no path, return -1.

## Example

**Example 1:**

```cpp
vector<vector<int>> grid = {
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1}
};

Output: 9
```

**Example 2:**

```cpp
vector<vector<int>> grid = {
    {1, 0, 0},
    {1, 1, 0},
    {0, 1, 1}
};

Output: 5
```