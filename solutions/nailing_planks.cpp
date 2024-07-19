#include <iostream>
#include <vector>
#include <queue>

bool canNail(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, int nailsCount)
{
    bool isNailed = false;
    for(auto i = 0; i < A.size(); ++i)
    {
        isNailed = false;
        for(auto n = 0; n < nailsCount; ++n)
        {
            if((A[i] <= C[n]) && (C[n] <= B[i]))
            {
                isNailed = true;
                break;
            }
        }
        if(!isNailed)
            return false;
    }
    return isNailed;
}

int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C)
{
    int min = 0;
    int max = C.size();
    int result = -1;

    // do binary search
    while(min <= max)
    {
        int mid = (min + max) / 2;
        if(canNail(A, B, C, mid))
        {
            result = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return result;
}

int main()
{
    std::vector<int> A = {1, 4, 5, 8};
    std::vector<int> B = {4, 5, 9, 10};
    std::vector<int> C = {4, 6, 7, 10, 2};

    int minNails = solution(A, B, C);
    std::cout << minNails << std::endl;
}
