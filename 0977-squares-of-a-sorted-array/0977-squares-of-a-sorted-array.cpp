class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Optimize standard I/O operations for competitive programming
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0;
        int right = n - 1;
        
        // Fill the result array from the highest value to the lowest value
        for (int i = n - 1; i >= 0; --i) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            if (leftSquare > rightSquare) {
                result[i] = leftSquare;
                left++;
            } else {
                result[i] = rightSquare;
                right--;
            }
        }
        
        return result;
    }
};
