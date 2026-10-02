class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // Find an empty cell
                if (board[i][j] == '.') {
                    // Try digits '1' through '9'
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // Place the digit
                            
                            // Recursively solve the rest of the board
                            if (solve(board)) {
                                return true;
                            }
                            
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // If no digit fits, this path is wrong
                }
            }
        }
        return true; // Entire board is filled successfully
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            // Check row constraint
            if (board[row][i] == c) return false;
            
            // Check column constraint
            if (board[i][col] == c) return false;
            
            // Check 3x3 sub-grid constraint
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};
