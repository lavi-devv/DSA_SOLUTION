#include <vector>

class NumArray {
private:
    std::vector<int> prefixSum;

public:
    // Constructor: Precompute the prefix sums
    NumArray(std::vector<int>& nums) {
        int n = nums.size();
        // Allocate size n + 1 to easily handle the left boundary (0)
        prefixSum.assign(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    
    // Query: Calculate the range sum in O(1) time
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left, right);
 */
