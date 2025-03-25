#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    ranges::sort(intervals);
    vector<vector<int>> ans;
    int n = intervals.size();
    for (int i = 0; i < n; i++) {
      int l = intervals[i][0], r = intervals[i][1];
      if (!ans.size() || ans.back()[1] < l) {
        ans.push_back({l, r});
      } else {
        ans.back()[1] = max(ans.back()[1], r);
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> intervals = {{1, 4}, {5, 6}};
  Solution sol = Solution();
  vector<vector<int>> ans = sol.merge(intervals);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}