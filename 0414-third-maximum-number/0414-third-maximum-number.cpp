#include <vector>
#include <climits>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        // Track top 3 maximums using long long to avoid INT_MIN edge cases
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int num : nums) {
            // Skip duplicates or elements already accounted for
            if (num == first || num == second || num == third) {
                continue;
            }

            // Update positions accordingly
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        // If the third maximum was never updated, return the absolute maximum
        if (third == LLONG_MIN) {
            return first;
        }

        return third;
    }
};
