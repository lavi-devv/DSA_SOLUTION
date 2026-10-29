
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueTypes(
            candyType.begin(), candyType.end()
        );

        return min((int)uniqueTypes.size(),
                   (int)candyType.size() / 2);
    }
};
