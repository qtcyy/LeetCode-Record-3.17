#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  int d1 = 0, d2 = 0;
  vector<vector<int>> g1, g2;

  int dfs1(int u, int fa) {
    int mx = 0;
    for (auto &v : g1[u]) {
      if (v == fa)
        continue;
      int len = dfs1(v, u) + 1;
      d1 = max(d1, mx + len);
      mx = max(mx, len);
    }
    return mx;
  };

  int dfs2(int u, int fa) {
    int mx = 0;
    for (auto &v : g2[u]) {
      if (v == fa)
        continue;
      int len = dfs2(v, u) + 1;
      d2 = max(d2, mx + len);
      mx = max(mx, len);
    }
    return mx;
  };

public:
  int minimumDiameterAfterMerge(vector<vector<int>> &edges1,
                                vector<vector<int>> &edges2) {
    int n = edges1.size(), m = edges2.size();
    g1.resize(n + 1);
    g2.resize(m + 1);
    for (auto &p : edges1) {
      g1[p[0]].push_back(p[1]);
      g1[p[1]].push_back(p[0]);
    }
    for (auto &p : edges2) {
      g2[p[0]].push_back(p[1]);
      g2[p[1]].push_back(p[0]);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    return ranges::max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
  }
};

signed main() {
  vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {2, 4},
                                {2, 5}, {3, 6}, {2, 7}},
                      edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 4},
                                {2, 5}, {3, 6}, {2, 7}};
  Solution sol;
  cout << sol.minimumDiameterAfterMerge(edges1, edges2) << endl;
  return 0;
}