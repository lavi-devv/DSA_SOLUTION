#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        // Start from index 1 and add the previous element to the current element
        for (size_t i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
