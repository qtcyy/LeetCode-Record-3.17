#include <bit>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minTransfers(vector<vector<int>> &transactions) {
    int n = 12;
    int cnt[12]{};
    for (auto &p : transactions) {
      cnt[p[0]] -= p[2];
      cnt[p[1]] += p[2];
    }
    vector<int> sum(1 << n);
    for (int s = 1; s < 1 << n; s++)
      for (int i = 0; i < n; i++) {
        if (s >> i & 1) {
          sum[s] += cnt[i];
        }
      }
    vector<int> f(1 << n);
    for (int s = 1; s < 1 << n; s++) {
      if (sum[s]) {
        f[s] = INT_MAX >> 1;
        continue;
      }
      f[s] = popcount((unsigned)s) - 1;
      for (int j = s; j; j = s & (j - 1)) {
        f[s] = min(f[s], f[j] + f[s ^ j]);
      }
    }
    return f.back();
  }
};

signed main() {
  vector<vector<int>> transactions = {
      {0, 1, 10}, {1, 0, 1}, {1, 2, 5}, {2, 0, 5}};
  Solution sol;
  cout << sol.minTransfers(transactions) << endl;

  return 0;
}