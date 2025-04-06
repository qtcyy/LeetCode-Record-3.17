#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

class Solution {
public:
  long long maxPower(vector<int> &stations, int r, int k) {
    int n = stations.size();
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + stations[i];
    }
    long long mn = LLONG_MAX, mx = 0;
    for (int i = 0; i < n; i++) {
      mn = min(mn, pre[min(n, i + r + 1)] - pre[max(0, i - r)]);
      mx = max(mx, pre[min(n, i + r + 1)] - pre[max(0, i - r)]);
    }
    auto check = [&](const ll &mid) -> bool {
      vector<ll> rem(n + 1, 0);
      ll rest = k;
      for (int i = 0; i < n; i++) {
        rem[i + 1] += rem[i];
        ll elec = pre[min(n, i + r + 1)] - pre[max(0, i - r)] + rem[i];
        if (elec < mid) {
          ll delta = mid - elec;
          if (delta <= rest) {
            rest -= delta;
            rem[i + 1] += delta;
            rem[min(n, i + 2 * r + 1)] -= delta;
          } else {
            return false;
          }
        }
      }
      return rest >= 0;
    };
    ll left = mn - 1, right = mx + 2 * k * r + 1;
    cout << left << ' ' << right << endl;
    while (left + 1 < right) {
      ll mid = (left + right) / 2;
      if (check(mid)) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return left;
  }
};

signed main() {
  vector<int> stations = {1, 2, 4, 5, 0};
  int r = 1, k = 2;
  Solution sol;
  cout << sol.maxPower(stations, r, k) << endl;

  return 0;
}