#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        // Step 1: Convert all integers to strings
        std::vector<std::string> strs;
        strs.reserve(nums.size());
        for (int num : nums) {
            strs.push_back(std::to_string(num));
        }
        
        // Step 2: Sort strings using a custom comparator
        // For two strings a and b, we check if (a + b) > (b + a)
        std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {
            return a + b > b + a;
        });
        
        // Step 3: Handle the edge case where all numbers are 0
        if (strs[0] == "0") {
            return "0";
        }
        
        // Step 4: Concatenate the sorted strings
        std::string result;
        for (const std::string& s : strs) {
            result += s;
        }
        
        return result;
    }
};
