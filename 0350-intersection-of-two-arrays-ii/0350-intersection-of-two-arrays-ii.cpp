#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> counts;
        std::vector<int> result;
        
        // Count frequencies of each number in the first array
        for (int num : nums1) {
            counts[num]++;
        }
        
        // Check elements of the second array against the map
        for (int num : nums2) {
            if (counts[num] > 0) {
                result.push_back(num);
                counts[num]--; // Decrease count to handle duplicates correctly
            }
        }
        
        return result;
    }
};
