#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int index, int target, std::vector<int>& candidates, 
                   std::vector<int>& currentPath, std::vector<std::vector<int>>& result) {
        // Base Case: If target is 0, we found a valid combination
        if (target == 0) {
            result.push_back(currentPath);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Pruning: Since the array is sorted, if the current element 
            // exceeds the target, all next elements will too.
            if (candidates[i] > target) {
                break;
            }

            // 1. Choose the current element
            currentPath.push_back(candidates[i]);

            // 2. Recurse (stay at index 'i' to allow unlimited reuse)
            backtrack(i, target - candidates[i], candidates, currentPath, result);

            // 3. Backtrack (undo the choice)
            currentPath.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentPath;

        // Sort candidates to enable early pruning
        std::sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, currentPath, result);
        return result;
    }
};
