#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        // Pre-allocate exact capacity (2^n) to eliminate reallocation overhead
        result.reserve(1 << nums.size()); 
        
        std::vector<int> current;
        current.reserve(nums.size());
        
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, int start, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Every recursive state represents a valid subset
        result.push_back(current);

        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);          // Include nums[i]
            backtrack(nums, i + 1, current, result);
            current.pop_back();                  // Backtrack (exclude nums[i])
        }
    }
};
