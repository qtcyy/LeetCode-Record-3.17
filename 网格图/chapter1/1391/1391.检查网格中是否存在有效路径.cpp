/*
 * @lc app=leetcode.cn id=1391 lang=cpp
 *
 * [1391] 检查网格中是否存在有效路径
 */
#include <functional>
#include <vector>
using namespace std;

// @lc code=start
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
  public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        bool is_valid = false;

        function<void(int, int)> dfs = [&](int x, int y) {};

        dfs(0, 0);
        return is_valid;
    }
};
// @lc code=end
