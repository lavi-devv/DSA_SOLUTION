class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    perimeter += 4; // Add 4 sides for the land cell
                    
                    // Check if the cell above is also land
                    if (r > 0 && grid[r - 1][c] == 1) {
                        perimeter -= 2;
                    }
                    // Check if the cell to the left is also land
                    if (c > 0 && grid[r][c - 1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        
        return perimeter;
    }
};
