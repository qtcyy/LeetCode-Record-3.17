#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
private:
  vector<bool> not_prime;
  set<int> pri;
  void pre(int n) {
    not_prime.resize(n + 1, false);
    for (int i = 2; i <= n; i++) {
      if (!not_prime[i]) {
        pri.insert(i);
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
  vector<vector<int>> findPrimePairs(int n) {
    pre(n);
    vector<vector<int>> ans;
    for (int i = 2; i * 2 <= n; i++) {
      if (pri.contains(i) && pri.contains(n - i)) {
        ans.push_back({i, n - i});
      }
    }
    return ans;
  }
};

signed main() {
  Solution sol = Solution();
  vector<vector<int>> ans = sol.findPrimePairs(10);
  for (auto &row : ans) {
    cout << row[0] << ' ' << row[1] << endl;
  }
  return 0;
}