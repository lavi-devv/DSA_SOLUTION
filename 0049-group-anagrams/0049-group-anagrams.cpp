#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Map to store: [sorted_string -> list of original anagrams]
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        
        for (const std::string& str : strs) {
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end()); // O(K log K)
            
            // Group the original string by its sorted key
            anagramMap[sortedStr].push_back(str);
        }
        
        // Collect all groups from the map
        std::vector<std::vector<std::string>> result;
        result.reserve(anagramMap.size());
        
        for (auto& pair : anagramMap) {
            result.push_back(std::move(pair.second));
        }
        
        return result;
    }
};
