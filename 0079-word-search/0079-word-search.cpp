#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.size();

        // 1. Early exit if word is longer than total grid cells
        if (len > m * n) return false;

        // 2. Frequency pruning: verify board has enough of every required letter
        int count[128] = {0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                count[board[i][j]]++;
            }
        }
        for (char c : word) {
            if (--count[c] < 0) return false;
        }

        // 3. Reverse pruning: start from the rarer endpoint to minimize DFS branches
        if (count[word[0]] > count[word.back()]) {
            reverse(word.begin(), word.end());
        }

        // 4. Standard grid scan
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int idx) {
        if (idx == word.size()) return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx]) {
            return false;
        }

        // Mark visited in-place using a non-alphabetic sentinel
        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, r + 1, c, idx + 1) ||
                     dfs(board, word, r - 1, c, idx + 1) ||
                     dfs(board, word, r, c + 1, idx + 1) ||
                     dfs(board, word, r, c - 1, idx + 1);

        // Restore original character (backtrack)
        board[r][c] = temp;
        return found;
    }
};
