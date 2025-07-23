/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
  public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        bool flag = true;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        function<void(int, int)> dfs = [&](int x, int y) {
            for (int k = 0; k < 4; k++) {
                int tx = x + dx[k], ty = y + dy[k];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m)
                    continue;
                if (grid2[tx][ty] == 1 && !vis[tx][ty]) {
                    if (grid1[tx][ty] == 0) {
                        flag = false;
                    }
                    vis[tx][ty] = true;
                    dfs(tx, ty);
                }
            }
        };

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    flag = true;
                    if (grid1[i][j] == 0)
                        flag = false;
                    vis[i][j] = true;
                    dfs(i, j);
                    if (flag)
                        ++ans;
                }
            }
        return ans;
    }
};
// @lc code=end
