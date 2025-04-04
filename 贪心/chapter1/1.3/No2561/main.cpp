#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  long long minCost(vector<int> &basket1, vector<int> &basket2) {
    unordered_map<int, int> cnt;
    int n = basket1.size();
    for (int i = 0; i < n; i++) {
      ++cnt[basket1[i]];
      --cnt[basket2[i]];
    }
    int mn = INT_MAX;
    vector<int> a;
    for (auto &[x, c] : cnt) {
      if (c % 2) {
        return -1;
      }
      mn = min(mn, x);
      for (c = abs(c) / 2; c > 0; --c) {
        a.push_back(x);
      }
    }
    long long ans = 0;
    ranges::nth_element(a, a.begin() + a.size() / 2);
    for (int i = 0; i < a.size() / 2; i++) {
      ans += min(mn * 2, a[i]);
    }
    return ans;
  }
};

signed main() {
  vector<int> basket1 = {4, 2, 2, 2}, basket2 = {1, 4, 1, 2};
  Solution sol;
  cout << sol.minCost(basket1, basket2) << endl;

  return 0;
}