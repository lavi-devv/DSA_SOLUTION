#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        // Fast I/O optimization for LeetCode
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1; // Flag to track if the first column needs to be zeroed

        // Step 1: Scan the matrix and use the first row/column as tracking markers
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Iterate backwards to safely update elements using the markers
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};
