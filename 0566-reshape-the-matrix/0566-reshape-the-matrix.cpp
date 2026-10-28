class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        // If the total number of elements doesn't match, the reshape is illegal
        if (m * n != r * c) {
            return mat;
        }
        
        // Initialize the reshaped matrix with the new dimensions
        vector<vector<int>> reshaped(r, vector<int>(c));
        
        // Map elements using mathematical index transformation
        for (int i = 0; i < m * n; ++i) {
            reshaped[i / c][i % c] = mat[i / n][i % n];
        }
        
        return reshaped;
    }
};
