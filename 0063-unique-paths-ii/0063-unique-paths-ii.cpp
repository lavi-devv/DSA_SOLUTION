class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If the starting or ending cell has an obstacle, no path is possible
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        
        // Use long long to prevent potential integer overflow on intermediate paths
        vector<long long> dp(n, 0);
        dp[0] = 1; // Starting position
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    // Obstacle blocks all paths through this cell
                    dp[j] = 0;
                } else if (j > 0) {
                    // Current ways = ways from top (current dp[j]) + ways from left (dp[j - 1])
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n - 1];
    }
};
