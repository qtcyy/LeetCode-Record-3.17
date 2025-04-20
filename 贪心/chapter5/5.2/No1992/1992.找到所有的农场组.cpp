/*
 * @lc app=leetcode.cn id=1992 lang=cpp
 *
 * [1992] 找到所有的农场组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>> &land) {
    int n = land.size(), m = land[0].size();
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (land[i][j] == 0)
          continue;
        int sx = i, sy = j;
        int tx = i, ty = j;
        while (ty < m && land[i][ty])
          ++ty;
        --ty;
        while (tx < n && land[tx][ty])
          ++tx;
        --tx;
        res.push_back({sx, sy, tx, ty});
        for (int x = sx; x <= tx; x++)
          for (int y = sy; y <= ty; y++)
            land[x][y] = 0;
      }
    }
    return res;
  }
};
// @lc code=end
