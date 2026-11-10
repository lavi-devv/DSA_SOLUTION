#include <vector>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Place each number in its correct index position if possible
        // A number x should be at index x - 1 (e.g., 1 at index 0, 2 at index 1)
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first index where the number doesn't match the index rule
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If all numbers from 1 to n are present, the answer is n + 1
        return n + 1;
    }
};
