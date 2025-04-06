#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int N = 10005;

signed main() {
  freopen("a.in", "r", stdin);
  int n, maxn = 0;
  cin >> n;
  vector<vector<int>> g(N, vector<int>(N, 0));
  vector<int> deg(N, 0);
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    maxn = max(maxn, max(u, v));
    ++g[u][v];
    ++g[v][u];
    ++deg[u];
    ++deg[v];
  }
  int s = 1;

  for (int i = 1; i <= maxn; i++) {
    if (deg[i] % 2) {
      s = i;
      break;
    }
  }

  vector<int> ans;
  function<void(int &)> dfs = [&](int &u) {
    for (int i = 1; i <= maxn; i++) {
      if (g[u][i] >= 1) {
        --g[u][i];
        --g[i][u];
        dfs(i);
      }
    }
    ans.push_back(u);
  };
  dfs(s);
  reverse(ans.begin(), ans.end());

  for (auto &x : ans) {
    cout << x << endl;
  }

  return 0;
}