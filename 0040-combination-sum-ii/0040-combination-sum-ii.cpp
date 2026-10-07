#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentCombination;
        
        // 1. Sort candidates to easily handle duplicates and optimize pruning
        std::sort(candidates.begin(), candidates.end());
        
        // 2. Start the recursive backtracking process
        backtrack(candidates, target, 0, currentCombination, result);
        
        return result;
    }

private:
    void backtrack(const std::vector<int>& candidates, int target, int startIndex, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: If target is met, record the combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            // Early pruning: Since the array is sorted, if the current element exceeds 
            // the target, all subsequent elements will also exceed it.
            if (candidates[i] > target) {
                break;
            }

            // Skip duplicates at the same recursion depth level to avoid duplicate sets
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Take the current element
            current.push_back(candidates[i]);
            
            // Move to the next element (i + 1 ensures each element is used only once)
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            
            // Backtrack: remove the element to explore other paths
            current.pop_back();
        }
    }
};
