#include <vector>
#include <algorithm>

class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int totalDuration = 0;
        
        // Loop through the series except for the last element
        for (size_t i = 0; i < timeSeries.size() - 1; ++i) {
            // Add either the actual time gap or the full duration, whichever is smaller
            totalDuration += std::min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        
        // The last attack always delivers the full duration of poison
        totalDuration += duration;
        
        return totalDuration;
    }
};
