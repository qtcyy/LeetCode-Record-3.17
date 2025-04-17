#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

class Solution {
public:
  long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price) {
    vector<vector<int>> g(n);
    for (auto &p : edges) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }
    ll ans = 0;
    function<pair<ll, ll>(int, int)> dfs = [&](int u, int fa) -> pair<ll, ll> {
      ll mx1 = price[u], mx2 = 0;
      for (auto &v : g[u]) {
        if (v == fa)
          continue;
        auto [s1, s2] = dfs(v, u);
        ans = max(ans, max(mx1 + s2, mx2 + s1));
        mx1 = max(mx1, s1 + price[u]);
        mx2 = max(mx2, s2 + price[u]);
      }
      return {mx1, mx2};
    };
    dfs(0, -1);
    return ans;
  }
};

signed main() {
  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}};
  vector<int> price = {9, 8, 7, 6, 10, 5};
  Solution sol;
  cout << sol.maxOutput(n, edges, price) << endl;

  return 0;
}