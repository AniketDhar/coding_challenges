#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int findPeakIndex(std::vector<int>& num)
{
    int low = 0;
    int high = num.size() - 1;

    while(low < high)
    {
        int mid = low + (high - low) / 2;
        if(num[mid] > num[mid+1])
            high = mid;
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    std::vector<int> num1 = {1, 2, 3, 1};
    std::vector<int> num2 = {1, 2, 1, 3, 5, 6, 4};
    std::vector<std::vector<int>> collection = {num1, num2};
    for(auto& num:collection)
    {
        int peakPosition = findPeakIndex(num);
        std::cout << peakPosition << std::endl;
    }
}
