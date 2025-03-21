#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> shortestDistanceColor(vector<int> &colors,
                                    vector<vector<int>> &queries) {
    vector<vector<int>> recorder(4);
    int n = colors.size();
    for (int i = 0; i < n; i++) {
      recorder[colors[i]].push_back(i);
    }
    vector<int> res;
    for (auto &q : queries) {
      if (recorder[q[1]].empty()) {
        res.push_back(-1);
        continue;
      }
      auto it = lower_bound(recorder[q[1]].begin(), recorder[q[1]].end(), q[0]);

      int dist = n;
      if (it != recorder[q[1]].end()) {
        dist = abs(q[0] - *(it));
      }
      if (it != recorder[q[1]].begin()) {
        dist = min(dist, abs(*(--it) - q[0]));
      }
      res.push_back(dist == n ? -1 : dist);
    }
    return res;
  }
};

signed main() {
  vector<int> colors = {1, 1, 2, 1, 3, 2, 2, 3, 3};
  vector<vector<int>> queries = {{1, 3}, {2, 2}, {6, 1}};
  Solution sol = Solution();
  vector<int> ans = sol.shortestDistanceColor(colors, queries);
  for (int &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}