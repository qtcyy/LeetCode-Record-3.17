#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[i + 1][j + 1] =
            sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int r2 = i; r2 < n; r2++) {
          for (int c2 = j; c2 < m; c2++) {
            int val = sum[r2 + 1][c2 + 1] - sum[r2 + 1][j] - sum[i][c2 + 1] +
                      sum[i][j];
            int area = (r2 - i + 1) * (c2 - j + 1);
            if (val == area) {
              ++ans;
            }
          }
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> mat = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
  Solution sol = Solution();
  cout << sol.numSubmat(mat) << endl;

  return 0;
}