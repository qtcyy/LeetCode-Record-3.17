#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> g[i][j];
  vector<vector<int>> f(n, vector<int>(1 << n, INT_MAX / 2));
  f[0][1] = 0;
  for (int s = 1; s < 1 << n; s++) {
    for (int i = 0; i < n; i++) {
      if (!(s >> i & 1))
        continue;
      int sub = s ^ (1 << i);
      for (int j = 0; j < n; j++) {
        if (i != j && sub >> j & 1) {
          f[i][s] = min(f[i][s], f[j][sub] + g[j][i]);
        }
      }
    }
  }
  cout << f[0].back() << '\n';
}

signed main() {
  freopen("a.in", "r", stdin);
  cin.tie(0)->sync_with_stdio(false);
  solve();

  return 0;
}