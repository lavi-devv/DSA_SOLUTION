#include <vector>
#include <string>
#include <cctype>

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::string>& words) {
        // Pre-mapping every alphabet character ('a' through 'z') to its respective keyboard row
        // Row 1: qwertyuiop, Row 2: asdfghjkl, Row 3: zxcvbnm
        std::vector<int> charToRow = {
            2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, // a-m
            3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3  // n-z
        };
        
        std::vector<std::string> result;
        
        for (const std::string& word : words) {
            if (word.empty()) continue;
            
            // Get the row of the first character to use as a baseline
            int targetRow = charToRow[std::tolower(word[0]) - 'a'];
            bool isValid = true;
            
            // Check if all subsequent characters match the baseline row
            for (char ch : word) {
                if (charToRow[std::tolower(ch) - 'a'] != targetRow) {
                    isValid = false;
                    break; // Move to the next word immediately if a mismatch is found
                }
            }
            
            if (isValid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
