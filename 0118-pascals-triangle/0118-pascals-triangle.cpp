#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            // Create a row of size (i + 1) filled entirely with 1s
            std::vector<int> row(i + 1, 1);
            
            // Calculate the internal elements using the previous row
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            // Add the constructed row to the final triangle
            triangle.push_back(row);
        }
        
        return triangle;
    }
};
