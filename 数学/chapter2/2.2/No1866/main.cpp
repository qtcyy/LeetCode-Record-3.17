#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int rearrangeSticks(int n, int k) {
    using ll = long long;
    vector<ll> f(k + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
      vector<ll> g(k + 1);
      for (int j = 1; j <= k; j++) {
        g[j] = (f[j - 1] + (i - 1) * f[j] % mod) % mod;
      }
      f = std::move(g);
    }
    return f[k];
  }
};

signed main() {
  int n = 20, k = 11;
  Solution sol;
  cout << sol.rearrangeSticks(n, k) << endl;

  return 0;
}