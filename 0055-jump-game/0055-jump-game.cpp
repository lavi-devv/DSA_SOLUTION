class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If the current index is beyond the maximum reachable index, we can't proceed
            if (i > maxReachable) {
                return false;
            }
            
            // Update the maximum reachable index from the current position
            maxReachable = max(maxReachable, i + nums[i]);
            
            // Optimization: If we can already reach the last index, return true early
            if (maxReachable >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};
