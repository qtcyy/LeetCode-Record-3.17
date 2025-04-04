#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

using ll = long long;

class Solution {
public:
  int findDerangement(int n) {
    vector<ll> f(n + 1);
    f[0] = 1;
    f[1] = 0;
    for (int i = 2; i <= n; i++) {
      f[i] = (i - 1ll) * (f[i - 1] + f[i - 2]) % mod;
    }
    return f[n];
  }
};

signed main() {
  int n = 3;
  Solution sol;
  cout << sol.findDerangement(n) << endl;

  return 0;
}