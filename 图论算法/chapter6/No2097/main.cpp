#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
    unordered_map<int, vector<int>> g;
    unordered_map<int, int> indeg, outdeg;
    for (auto &p : pairs) {
      g[p[0]].push_back(p[1]);
      ++indeg[p[1]];
      ++outdeg[p[0]];
    }
    int s = pairs[0][0];
    for (auto &&[u, deg] : outdeg) {
      if (deg == indeg[u] + 1) {
        s = u;
        break;
      }
    }
    vector<vector<int>> ans;
    function<void(int &)> dfs = [&](int &u) {
      while (!g[u].empty()) {
        int v = g[u].back();
        g[u].pop_back();
        dfs(v);
        ans.push_back({u, v});
      }
    };
    dfs(s);
    reverse(ans.begin(), ans.end());

    return ans;
  }
};

signed main() {
  vector<vector<int>> pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
  Solution sol;
  auto ans = sol.validArrangement(pairs);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}