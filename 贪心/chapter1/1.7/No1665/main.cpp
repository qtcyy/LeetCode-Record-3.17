#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumEffort(vector<vector<int>> &tasks) {
    ranges::sort(tasks,
                 [](auto &a, auto &b) { return a[1] - a[0] < b[1] - b[0]; });
    int ans = 0;
    for (auto &p : tasks) {
      ans += p[0];
      ans = max(ans, p[1]);
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> tasks = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
  Solution sol;
  cout << sol.minimumEffort(tasks) << endl;

  return 0;
}