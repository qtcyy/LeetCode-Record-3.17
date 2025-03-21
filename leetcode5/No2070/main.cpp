#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    sort(items.begin(), items.end(),
         [](const auto &p1, const auto &p2) { return p1[0] < p2[0]; });
    int n = items.size();
    vector<int> pre_max(n, 0);
    pre_max[0] = items[0][1];
    for (int i = 1; i < n; i++) {
      pre_max[i] = max(pre_max[i - 1], items[i][1]);
    }
    for (auto &q : queries) {
      auto it =
          ranges::upper_bound(items, q, {}, [](auto &item) { return item[0]; });
      if (it == items.begin()) {
        q = 0;
      } else if (it == items.end()) {
        q = pre_max.back();
      } else {
        q = pre_max[(int)(it - items.begin() - 1)];
      }
    }
    return queries;
  }
};

signed main() {
  vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
  vector<int> queries = {1, 2, 3, 4, 5, 6};
  Solution sol = Solution();
  vector<int> ans = sol.maximumBeauty(items, queries);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}