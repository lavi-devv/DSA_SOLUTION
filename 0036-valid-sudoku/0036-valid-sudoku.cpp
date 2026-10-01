#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Track seen numbers for rows, columns, and 3x3 boxes
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                // Skip empty cells
                if (board[r][c] == '.') {
                    continue;
                }
                
                // Convert char digit to a 0-indexed integer (0 to 8)
                int num = board[r][c] - '1';
                
                // Calculate the 3x3 box index (0 to 8)
                int box_index = (r / 3) * 3 + (c / 3);
                
                // Check if the number already exists in the current row, column, or box
                if (rows[r][num] || cols[c][num] || boxes[box_index][num]) {
                    return false;
                }
                
                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box_index][num] = true;
            }
        }
        
        return true;
    }
};
