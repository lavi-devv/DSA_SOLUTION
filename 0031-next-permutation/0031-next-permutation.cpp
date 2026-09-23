#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        
        // Step 1: Find the first decreasing element from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        // Step 2: If a valid pivot is found, find the element just larger than nums[pivot] from the right
        if (pivot != -1) {
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    std::swap(nums[pivot], nums[i]);
                    break;
                }
            }
        }
        
        // Step 3: Reverse the elements to the right of the pivot
        std::reverse(nums.begin() + pivot + 1, nums.end());
    }
};
