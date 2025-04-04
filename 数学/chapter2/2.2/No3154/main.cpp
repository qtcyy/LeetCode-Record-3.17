#include <iostream>
using namespace std;

int c[31][31];

auto init = [] {
  for (int i = 1; i < 31; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }
  return 0;
}();

class Solution {
public:
  int waysToReachStair(int k) {
    int ans = 0;
    for (int j = 0; j < 30; j++) {
      int m = (1 << j) - k;
      if (0 <= m && m <= j + 1) {
        ans += c[j + 1][m];
      }
    }
    return ans;
  }
};

signed main() {
  int k = 1;
  Solution sol;
  cout << sol.waysToReachStair(k) << endl;

  return 0;
}