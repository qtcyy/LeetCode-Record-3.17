#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

class Solution {
public:
  int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes) {
    ranges::sort(packages);
    for (auto &box : boxes) {
      ranges::sort(box);
    }
    int n = packages.size();
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + packages[i];
    }
    ll ans = LLONG_MAX;
    for (auto &box : boxes) {
      if (packages.back() > box.back()) {
        continue;
      }
      auto pt = packages.begin(), dummy = packages.begin();
      ll tot = 0;
      for (auto &x : box) {
        if (*pt > x) {
          continue;
        }
        auto next_pt = prev(upper_bound(packages.begin(), packages.end(), x));
        tot = tot + 1ll * (next_pt - pt + 1) * x - pre[next_pt - dummy + 1] +
              pre[pt - dummy];
        pt = next(next_pt);
        if (pt == packages.end()) {
          break;
        }
      }
      ans = min(ans, tot);
    }
    return ans >= LLONG_MAX ? -1 : ans % mod;
  }
};

signed main() {
  vector<int> packages = {3, 5, 8, 10, 11, 12};
  vector<vector<int>> boxes = {{12}, {11, 9}, {10, 5, 14}};
  Solution sol;
  cout << sol.minWastedSpace(packages, boxes) << endl;

  return 0;
}