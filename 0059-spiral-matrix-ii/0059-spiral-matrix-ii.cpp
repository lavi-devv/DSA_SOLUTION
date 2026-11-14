#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        
        while (top <= bottom && left <= right) {
            // 1. Fill top row (left to right)
            for (int col = left; col <= right; ++col) {
                matrix[top][col] = num++;
            }
            ++top;
            
            // 2. Fill right column (top to bottom)
            for (int row = top; row <= bottom; ++row) {
                matrix[row][right] = num++;
            }
            --right;
            
            // 3. Fill bottom row (right to left)
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    matrix[bottom][col] = num++;
                }
                --bottom;
            }
            
            // 4. Fill left column (bottom to top)
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    matrix[row][left] = num++;
                }
                ++left;
            }
        }
        
        return matrix;
    }
};
