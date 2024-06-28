# Coding Challenge: Mouse and Cheese in a Maze

## Problem Statement
You are given a maze represented as a 2D grid. Each cell in the grid can be either open (0), a wall (1), a mouse (M), or a cheese (C). The maze can contain multiple mice, but only one piece of cheese. Your task is to find the shortest path from any mouse to the cheese. You can move up, down, left, or right.

Write a function `shortestPathToCheese` that takes the 2D grid as input and returns the length of the shortest path from any mouse to the cheese. If there is no path, return -1.

## Input
A 2D grid of size n x m where each cell is either 0, 1, M, or C.

## Output
An integer representing the length of the shortest path from any mouse to the cheese. If there is no path, return -1.

## Constraints
- The grid will have at least one row and one column.
- There will be exactly one C (cheese) in the grid.
- There can be multiple M (mouse) starting points in the grid.

## Example

**Example 1:**
```cpp
vector<vector<char>> grid = {
    {'M', '0', '1', '0', 'C'},
    {'1', '0', '1', '0', '1'},
    {'0', '0', '0', '0', '0'},
    {'1', '1', '1', '1', '0'},
    {'M', '0', '0', '0', '0'}
};

Output: 8
```

**Example 2:**
```cpp
vector<vector<char>> grid = {
    {'M', '1', '1', '1', 'C'},
    {'1', '1', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'M', '1', '1', '1', '1'},
    {'0', '0', '0', '0', '0'}
};

Output: -1
```