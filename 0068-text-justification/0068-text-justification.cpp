#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        // Optimize standard I/O operations for performance competitive-style
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        std::vector<std::string> result;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            // Step 1: Find out how many words can fit in the current line
            int j = i + 1;
            int lineLength = words[i].length();
            
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }
            
            std::string line = "";
            int numWords = j - i;
            int numGaps = numWords - 1;
            
            // Step 2: Handle Edge Case - Last line or a line containing only one word
            if (j == n || numWords == 1) {
                // Left-justify formatting
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                // Pad remaining spaces to the right
                line += std::string(maxWidth - line.length(), ' ');
            } 
            // Step 3: Round-Robin justification for typical middle lines
            else {
                // Calculate the actual string length of all words without tracking mandatory spaces
                int totalWordChars = 0;
                for (int k = i; k < j; ++k) {
                    totalWordChars += words[k].length();
                }
                
                int totalSpaces = maxWidth - totalWordChars;
                int baseSpaces = totalSpaces / numGaps;
                int extraSpaces = totalSpaces % numGaps;
                
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        // Distribute standard base spaces + 1 remainder space from left to right if available
                        int spacesToAdd = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line += std::string(spacesToAdd, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j; // Move to the first word of the next line
        }
        
        return result;
    }
};
