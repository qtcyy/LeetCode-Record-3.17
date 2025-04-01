#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxGcdSum(vector<int> &nums, int k) {
    using ll = long long;
    int n = nums.size();
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++)
      pre[i + 1] = pre[i] + nums[i];
    vector<pair<int, int>> g;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      g.emplace_back(nums[i], i);
      int j = 0;
      for (auto &p : g) {
        p.first = gcd(p.first, nums[i]);
        if (g[j].first == p.first) {
          continue;
        } else {
          g[++j] = std::move(p);
        }
      }
      g.resize(j + 1);
      for (auto &&[val, pos] : g) {
        if (i - pos + 1 >= k) {
          ans = max(ans, val * (pre[i + 1] - pre[pos]));
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {2, 1, 4, 4, 4, 2};
  int k = 2;
  Solution sol;
  cout << sol.maxGcdSum(nums, k) << endl;

  return 0;
}