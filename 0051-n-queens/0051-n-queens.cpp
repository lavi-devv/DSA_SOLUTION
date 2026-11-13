class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, 0, 0, 0, board, res);
        return res;
    }

private:
    void backtrack(int row, int n, int cols, int diag1, int diag2,
                   vector<string>& board, vector<vector<string>>& res) {
        // Base case: all n queens have been placed safely
        if (row == n) {
            res.push_back(board);
            return;
        }

        // Create a bitmask of all valid columns in the current row
        // (1 << n) - 1 sets the lowest n bits to 1
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (available) {
            // Extract the rightmost available bit (lowest set bit)
            int bit = available & -available;
            
            // Convert the bit position to a 0-indexed column number
            int col = __builtin_ctz(bit);

            // Place the queen
            board[row][col] = 'Q';

            // Recurse to the next row, shifting diagonals left and right
            backtrack(row + 1, n, 
                      cols | bit, 
                      (diag1 | bit) << 1, 
                      (diag2 | bit) >> 1, 
                      board, res);

            // Backtrack: remove the queen
            board[row][col] = '.';

            // Clear the rightmost set bit to try the next valid position
            available &= available - 1;
        }
    }
};
