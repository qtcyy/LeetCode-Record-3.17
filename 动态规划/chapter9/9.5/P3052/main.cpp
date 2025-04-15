#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int solve() {
  int n, w;
  cin >> n >> w;
  vector<int> a(n), cnt(1 << n, INT_MAX / 2);
  vector<int> f(1 << n, INT_MAX);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  //   ranges::sort(a);
  f[0] = 1;
  cnt[0] = 0;
  for (int s = 0; s < 1 << n; s++) {
    for (int i = 0; i < n; i++) {
      if (s >> i & 1)
        continue;
      int nxt = s | (1 << i);
      int add = cnt[s] + a[i];
      if (add <= w) {
        if (f[nxt] >= f[s]) {
          f[nxt] = f[s];
          cnt[nxt] = min(cnt[nxt], add);
        }
      } else {
        if (f[nxt] >= f[s] + 1) {
          f[nxt] = f[s] + 1;
          cnt[nxt] = min(cnt[nxt], a[i]);
        }
      }
    }
  }
  return f.back();
}

signed main() {
  freopen("a.in", "r", stdin);
  cin.tie(0)->sync_with_stdio(false);
  int ans = solve();
  cout << ans << '\n';

  return 0;
}