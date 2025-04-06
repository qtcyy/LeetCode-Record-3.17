#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    int n = grid.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int need = n - i - 1;
      int cnt = 0;
      for (int j = n - 1; j > i; j--) {
        cnt += (grid[i][j] == 0);
      }
      if (cnt >= need) {
        continue;
      }
      int pos = -1;
      for (int nxt = i + 1; nxt < n; nxt++) {
        bool flag = true;
        for (int j = n - 1; j > i; j--) {
          if (grid[nxt][j]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          pos = nxt;
          break;
        }
      }
      if (pos == -1) {
        return -1;
      }
      ans += pos - i;
      for (int k = pos; k > i; k--) {
        swap(grid[k], grid[k - 1]);
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
  Solution sol;
  cout << sol.minSwaps(grid) << endl;
}