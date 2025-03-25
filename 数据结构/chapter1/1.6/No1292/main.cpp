#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[i + 1][j + 1] =
            sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + mat[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int max_len = min(n - 1 - i, m - 1 - j);
        for (int len = 0; len <= max_len; len++) {
          int r2 = i + len, c2 = j + len;
          int val =
              sum[r2 + 1][c2 + 1] - sum[r2 + 1][j] - sum[i][c2 + 1] + sum[i][j];
          if (val <= threshold) {
            ans = max(ans, len + 1);
          }
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> mat = {
      {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};
  int threshold = 4;
  Solution sol = Solution();
  cout << sol.maxSideLength(mat, threshold) << endl;

  return 0;
}