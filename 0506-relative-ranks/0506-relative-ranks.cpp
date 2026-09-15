#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        vector<int> indices(n);
        
        // Fill the indices vector with 0, 1, ..., n-1
        iota(indices.begin(), indices.end(), 0);
        
        // Sort indices based on the scores in descending order
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return score[a] > score[b];
        });
        
        // Assign medals and placements
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ans[indices[i]] = "Gold Medal";
            } else if (i == 1) {
                ans[indices[i]] = "Silver Medal";
            } else if (i == 2) {
                ans[indices[i]] = "Bronze Medal";
            } else {
                ans[indices[i]] = to_string(i + 1);
            }
        }
        
        return ans;
    }
};
