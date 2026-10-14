class Solution {
private:
    void backtrack(int index, vector<int>& nums, vector<vector<int>>& result) {
        // Base case: if we reach the end of the array, a valid permutation is formed
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = index; i < nums.size(); ++i) {
            std::swap(nums[index], nums[i]);       // Swap to place element at the current position
            backtrack(index + 1, nums, result);   // Recurse for the next position
            std::swap(nums[index], nums[i]);       // Backtrack (restore original state)
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Optimize I/O operations for competitive programming competitive execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};
