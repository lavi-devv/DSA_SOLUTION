#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // Base case: If there are fewer than 4 elements, no quadruplet can be formed
        if (n < 4) return result;
        
        // Step 1: Sort the array to facilitate the two-pointer technique
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Loop through the first element
        for (int i = 0; i < n - 3; i++) {
            // Avoid duplicates for the first position
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Optimization: If the smallest possible sum is greater than target, break
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // Optimization: If the largest possible sum with current i is less than target, skip
            if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            
            // Step 3: Loop through the second element
            for (int j = i + 1; j < n - 2; j++) {
                // Avoid duplicates for the second position
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                // Optimization: Check bounds for the second element
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                
                // Step 4: Use two pointers for the remaining two elements
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long current_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (current_sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third pointer
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for the fourth pointer
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (current_sum < target) {
                        left++; // Increase sum
                    } else {
                        right--; // Decrease sum
                    }
                }
            }
        }
        
        return result;
    }
};
