#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/* The canDivide function checks if it's possible to partition the array 
into K or fewer blocks such that no block has a sum greater than mid. */
bool canDivide(std::vector<int>& A, int K, int maxSum)
{
    // greedy algorithm check
    int currentSum = 0;
    int required_blocks = 1;

    for(const auto& a : A)
    {
        if (currentSum + a > maxSum)
        {
            required_blocks++;
            currentSum = a;
            if (required_blocks > K)
                return false;
        }
        else
        {
            currentSum += a;
        }
    }
    return true;
}

int solution(int K, int M, std::vector<int>& A)
{
    int low = *std::max_element(A.begin(), A.end()); // sum can not be lower than the highest element in A
    int high = std::accumulate(A.begin(), A.end(), 0); // sum cannot be higher than the sum of all the elements in A

    // do binary search
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (canDivide(A, K, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    } 
    return low;
}

int main()
{
    std::vector<int> A = {0}; //{2, 1, 5, 1, 2, 2, 2};
    int K = 1; //3;
    int M = 1; //5;
    int minmaxSum = solution(K, M, A);
    std::cout << minmaxSum << std::endl;
}