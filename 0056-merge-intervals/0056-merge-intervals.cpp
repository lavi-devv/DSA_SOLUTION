#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        // Handle empty input edge case
        if (intervals.empty()) return {};

        // Step 1: Sort the intervals based on their start times
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;

        // Step 2: Iterate through sorted intervals
        for (const auto& interval : intervals) {
            // If the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } 
            // Otherwise, there is an overlap, so we merge the current 
            // interval into the previous one by updating the end time.
            else {
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
