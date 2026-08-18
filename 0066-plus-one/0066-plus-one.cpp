#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        // Traverse from the least significant digit (right to left)
        for (int i = digits.size() - 1; i >= 0; --i) {
            // If the digit is less than 9, just increment and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // If the digit is 9, it becomes 0 (carry moves to the next left digit)
            digits[i] = 0;
        }
        
        // If all digits were 9 (e.g., 999), the loop finishes and we need a leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
