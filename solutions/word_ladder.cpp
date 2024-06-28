#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

std::vector<std::string> shortestTransform(const std::string beginWord, 
                                        const std::string endWord, 
                                        const std::vector<std::string> wordList)
{
    // Create a set for the word list for quick lookup
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
    std::vector<std::string> sequence;

    // If endWord is not in dictionary word list
    if(wordSet.find(endWord) == wordSet.end())
        return sequence;

    // Create a queue for BFS
    std::queue<std::pair<std::string, int>> q;
    q.push({beginWord, 1}); // initialize with beginWord

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        std::string currentWord = current.first;
        int currentLength = current.second;

        // For each character in the current word, try to change it to all possible characters
        for(char& wc : currentWord)
        {
            char ogChar = wc; 
            for(char c='a'; c <= 'z'; ++c)
            {
                wc = c;

                // if transformed word is the endWord, return curr length + 1
                if(currentWord == endWord)
                    return sequence;

                // If the transformed word is in the word list, add it to the queue and remove it from the set
                if(wordSet.find(currentWord) != wordSet.end())
                {
                    q.push({currentWord, currentLength + 1});
                    sequence.emplace_back(currentWord);
                    wordSet.erase(currentWord);
                }
            }
            wc = ogChar;
        }
    }
   
    return sequence;

}

int main()
{
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    std::vector<std::string> sequence = shortestTransform(beginWord, endWord, wordList);
    for(const auto& s: sequence)
    {
        std::cout << s << std::endl;
    }
    std::cout << std::endl;
    std::cout << sequence.size() << std::endl;
}