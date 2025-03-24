#include <iostream>
#include <vector>

int maxBinaryGap(int number)
{
    if (number == 0)
        return 0;

    int max_gap = 0;
    int current_gap = 0;
    bool first_one = false;

    for (auto i = 0; i < sizeof(number)*8; ++i)
    {
        int bit = (number >> i) & 1;
        if(bit)
        {
            if(!first_one)
                first_one = true;
            else
            {
                if(current_gap > max_gap)
                {
                    max_gap = current_gap;
                }
                current_gap = 0;
            }
        }
        else
        {
            if(first_one)
                current_gap++;
        }
    }

    return max_gap;
}

int main()
{
    std::vector<int> nums = {2, 9, 11, 15, 20, 32};

    for(const auto& n : nums)
    {
        std::cout << "Binary Gap : " << maxBinaryGap(n) << std::endl;
    }
}