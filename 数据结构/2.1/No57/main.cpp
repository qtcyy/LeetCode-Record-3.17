#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> ans;
    intervals.push_back(newInterval);
    ranges::sort(intervals);
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
  vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval = {4, 8};
  Solution sol = Solution();
  vector<vector<int>> ans = sol.insert(intervals, newInterval);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}