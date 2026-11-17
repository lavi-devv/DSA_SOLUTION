#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;                   // Boundary for 0s (red)
        int mid = 0;                   // Current element under inspection
        int high = nums.size() - 1;    // Boundary for 2s (blue)

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
                // Do not increment mid here, as the swapped element from high needs to be checked
            }
        }
    }
};
