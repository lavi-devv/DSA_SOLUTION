class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int curr_sum = 0;
        
        for (int num : nums) {
            // Add the current element to our running sum
            curr_sum += num;
            
            // Track the maximum sum found so far
            max_sum = max(max_sum, curr_sum);
            
            // If the running sum drops below zero, reset it to zero
            // because a negative sum will only decrease the potential max of future subarrays
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }
        
        return max_sum;
    }
};
