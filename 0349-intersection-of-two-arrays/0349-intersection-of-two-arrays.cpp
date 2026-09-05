#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Insert all elements of the first array into a set
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> resultSet;
        
        // Check if elements of the second array exist in the set
        for (int num : nums2) {
            if (set1.count(num)) {
                resultSet.insert(num); // resultSet automatically handles duplicates
            }
        }
        
        // Convert the result set back to a vector
        return std::vector<int>(resultSet.begin(), resultSet.end());
    }
};
