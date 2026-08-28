#include <vector>
#include <unordered_map>
#include <cmath>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> num_to_index;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Check if the number already exists in the map
            if (num_to_index.find(nums[i]) != num_to_index.end()) {
                // Check if the distance between indices is <= k
                if (i - num_to_index[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the map with the latest index of the number
            num_to_index[nums[i]] = i;
        }
        
        return false;
    }
};
