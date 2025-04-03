#include <iostream>
using namespace std;

using ll = long long;

class Solution {
  ll comb(int n, int k) {
    k = min(k, n - k);
    ll res = 1;
    for (int i = 1; i <= k; i++) {
      res = res * (n - i + 1) / i;
    }
    return res;
  }

public:
  int uniquePaths(int m, int n) { return comb(n + m - 2, n - 1); }
};

signed main() {
  Solution sol;
  cout << sol.uniquePaths(3, 7) << endl;

  return 0;
}