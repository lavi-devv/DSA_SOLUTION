#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // We don't need to process the last element because 
        // once we reach or pass it, we are done.
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the farthest point we can reach from the current index
            farthest = std::max(farthest, i + nums[i]);
            
            // If we have reached the end of the current jump range
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                // If we can already reach the last index, we can stop early
                if (current_end >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};
