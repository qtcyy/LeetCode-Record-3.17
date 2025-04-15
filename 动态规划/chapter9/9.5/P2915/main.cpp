#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<ll>> f(n, vector<ll>(1 << n));
  for (int i = 0; i < n; i++)
    f[i][1 << i] = 1;
  for (int i = 1; i < 1 << n; i++) {
    for (int j = 0; j < n; j++) {
      if (!(i >> j & 1))
        continue;
      int sub = i ^ (1 << j);
      for (int t = 0; t < n; t++) {
        if (t == j)
          continue;
        if (abs(a[t] - a[j]) > k) {
          f[j][i] += f[t][sub];
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans += f[i].back();
  cout << ans << '\n';
}

signed main() {
  freopen("a.in", "r", stdin);
  cin.tie(0)->sync_with_stdio(false);
  solve();

  return 0;
}