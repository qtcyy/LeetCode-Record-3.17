#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<bool> not_prime;
  vector<int> pri;
  void pre(int n) {
    not_prime.resize(n + 1, false);
    for (int i = 2; i <= n; i++) {
      if (!not_prime[i]) {
        pri.push_back(i);
      }
      for (auto &p : pri) {
        if (i * p > n)
          break;
        not_prime[i * p] = 1;
        if (i % p == 0)
          break;
      }
    }
  }

public:
  vector<int> closestPrimes(int left, int right) {
    if (left == right || right <= 1) {
      return {-1, -1};
    }
    pre(right);
    auto start = upper_bound(pri.begin(), pri.end(), left);
    if (start == pri.end() || start == pri.end() - 1) {
      return {-1, -1};
    }
    vector<int> res(2);
    const int INF = 0x3f3f3f3f;
    int minn = INF;
    for (auto it = start; it != pri.end() - 1; ++it) {
      if (*(it + 1) - *it < minn) {
        minn = *(it + 1) - *it;
        res = {*it, *(it + 1)};
      }
    }
    if (minn == INF) {
      return {-1, -1};
    }
    return res;
  }
};

signed main() {
  Solution sol = Solution();
  vector<int> ans = sol.closestPrimes(10, 19);
  cout << ans[0] << ' ' << ans[1] << endl;

  return 0;
}