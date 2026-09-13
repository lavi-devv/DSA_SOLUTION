#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> nextGreaterMap;
        std::stack<int> st;

        // Traverse nums2 to find the next greater element for each number
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreaterMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Build the result for nums1 using the map
        std::vector<int> ans;
        for (int num : nums1) {
            if (nextGreaterMap.count(num)) {
                ans.push_back(nextGreaterMap[num]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
