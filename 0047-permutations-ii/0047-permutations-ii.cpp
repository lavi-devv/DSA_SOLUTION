#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentPermutation;
        std::vector<bool> used(nums.size(), false);
        
        // 1. Sort the numbers to place duplicates next to each other
        std::sort(nums.begin(), nums.end());
        
        // 2. Start the backtracking process
        backtrack(nums, used, currentPermutation, result);
        
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, 
                   std::vector<bool>& used, 
                   std::vector<int>& currentPermutation, 
                   std::vector<std::vector<int>>& result) {
        
        // Base case: If the current permutation matches the input size, store it
        if (currentPermutation.size() == nums.size()) {
            result.push_back(currentPermutation);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            // Skip if the element is already used in the current path
            if (used[i]) continue;
            
            // Skip duplicate elements to prevent duplicate branches
            // Only use the element if its identical predecessor has been used in this path
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            
            // Choose the element
            used[i] = true;
            currentPermutation.push_back(nums[i]);
            
            // Explore deeper paths
            backtrack(nums, used, currentPermutation, result);
            
            // Clean up / Backtrack
            currentPermutation.pop_back();
            used[i] = false;
        }
    }
};
