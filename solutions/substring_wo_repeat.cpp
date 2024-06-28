#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

/*
Solution Outline
- Initialize a sliding window using two pointers.
- Use a hash map (or array) to store the last seen index of each character.
- Iterate through the string, adjusting the window to ensure all characters within the window are unique.
- Track the maximum length of the substring found.
- O(n) time complexity
*/

std::string shortestSubstrNoRepeat(const std::string& s)
{
    std::unordered_map<char, int> hashmap;
    int start = 0;
    int maxLength = 0;
    int maxStart = 0; // start index of the max substr

    for(auto i = 0; i < s.length(); ++i)
    {
        if(hashmap.find(s[i]) != hashmap.end() && hashmap[s[i]] >= start)
        {
            start = hashmap[s[i]] + 1;
        }
        hashmap[s[i]] = i;
        // maxLength = std::max(maxLength, i-start+1);
        // if( i - start + 1 > maxLength)
        // {
        //     maxLength = i-start+1;
        //     maxStart = start;
        // }
    }
    return s.substr(maxStart, maxLength);
}

int main()
{
    std::string s = "abcabcbb";
    std::vector<std::string> collection = {{"abcabcbb"}, {"bbbbb"}, {"pwwkew"}, {""}};

    for( const auto& s : collection)
    {
        std::string longestSubstr = shortestSubstrNoRepeat(s);
        std::cout << longestSubstr << " " << longestSubstr.length() << std::endl;
    }
}