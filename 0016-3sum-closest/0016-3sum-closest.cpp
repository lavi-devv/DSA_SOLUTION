#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to use the two-pointer technique
        std::sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If we find the exact target, return it immediately
                if (currentSum == target) {
                    return currentSum;
                }
                
                // Update closestSum if the current triplet is closer to the target
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move pointers based on how currentSum compares to target
                if (currentSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return closestSum;
    }
};
