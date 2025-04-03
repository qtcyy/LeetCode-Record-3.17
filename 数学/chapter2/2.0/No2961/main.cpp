#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
    auto qpow = [](int x, int n, int mod) -> int {
      int res = 1;
      while (n) {
        if (n & 1) {
          res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
      }
      return res;
    };
    vector<int> ans;
    int n = variables.size();
    for (int i = 0; i < n; i++) {
      auto &var = variables[i];
      int a = var[0], b = var[1], c = var[2], m = var[3];
      int val = qpow(qpow(a, b, 10), c, m);
      if (val == target) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> variables = {{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}};
  int target = 2;
  Solution sol;
  auto ans = sol.getGoodIndices(variables, target);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}