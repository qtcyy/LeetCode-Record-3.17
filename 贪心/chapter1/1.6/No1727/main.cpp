#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int largestSubmatrix(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 1) {
          matrix[i][j] += matrix[i - 1][j];
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ranges::sort(matrix[i]);
      for (int j = m - 1; j >= 0; j--) {
        int h = matrix[i][j];
        ans = max(ans, h * (m - j));
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> matrix = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
  Solution sol;
  cout << sol.largestSubmatrix(matrix) << endl;

  return 0;
}