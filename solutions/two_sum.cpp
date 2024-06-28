#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> hashMap;

    for(int i = 0; i < nums.size(); ++i)
    {
        auto complement = target - nums[i];
        if(hashMap.find(complement) != hashMap.end())
        {
            return {hashMap[complement], i};
        }
        hashMap[nums[i]] = i;
        // When we search for the complement of the current element, we need to ensure that the complement is not the current element itself.
        // By checking for the complement before adding the current element to the map, we ensure that the complement is always a previously encountered element.
    }
    return {};
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> indices = twoSum(nums, target);

    for(const auto& id : indices)
        std::cout << id << std::endl; 

}