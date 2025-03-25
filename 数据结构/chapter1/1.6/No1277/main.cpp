#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[i + 1][j + 1] =
            sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int max_len = min(n - 1 - i, m - 1 - j);
        for (int len = 0; len <= max_len; len++) {
          int r2 = i + len, c2 = j + len;
          int val =
              sum[r2 + 1][c2 + 1] - sum[i][c2 + 1] - sum[r2 + 1][j] + sum[i][j];
          if (val == (len + 1) * (len + 1)) {
            ans++;
          }
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
  Solution sol = Solution();
  cout << sol.countSquares(matrix) << endl;

  return 0;
}