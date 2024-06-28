# Coding Challenge: Word Ladder
## Problem Statement
Given two words, `beginWord` and `endWord`, and a dictionary's word list, find the length of the shortest transformation sequence from beginWord to endWord, such that:

- Only one letter can be changed at a time.
- Each transformed word must exist in the word list.
- Return the length of the shortest transformation sequence. If no such sequence exists, return 0.

**Note:**
- Return 0 if endWord is not in the word list.
- All words have the same length.
- All words contain only lowercase alphabetic characters.
- You may assume no duplicates in the word list.
- You may assume beginWord and endWord are non-empty and are not the same.

### Input
- `beginWord`: a string representing the initial word.
- `endWord`: a string representing the target word.
- `wordList`: a list of strings representing the dictionary of words.

### Output
An integer representing the length of the shortest transformation sequence.

## Example

**Example 1:**

```c++
string beginWord = "hit";
string endWord = "cog";
vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
```

Output: 5 (Explanation: "hit" -> "hot" -> "dot" -> "dog" -> "cog")

**Example 2:**

```c++
string beginWord = "hit";
string endWord = "cog";
vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
```

Output: 0 (Explanation: The endWord "cog" is not in the word list, so the transformation is not possible.)
