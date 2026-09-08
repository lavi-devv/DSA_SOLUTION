class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Mark seen numbers by negating the value at the corresponding index
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        vector<int> ans;
        // Indices with positive values indicate missing numbers
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            } else {
                nums[i] = -nums[i]; // Restore original array (optional)
            }
        }
        
        return ans;
    }
};
