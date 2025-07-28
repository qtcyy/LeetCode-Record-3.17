/*
 * @lc app=leetcode.cn id=2428 lang=cpp
 *
 * [2428] 沙漏的最大总和
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                int rest = grid[i + 1][j] + grid[i + 1][j + 2];
                int sum = 0;
                for (int x = i; x <= i + 2; x++)
                    for (int y = j; y <= j + 2; y++)
                        sum += grid[x][y];
                ans = max(ans, sum - rest);
            }
        }
        return ans;
    }
};
// @lc code=end
