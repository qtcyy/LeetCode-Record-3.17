#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int minGroups(vector<vector<int>> &intervals) {
    ranges::sort(intervals);
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto &x : intervals) {
      if (!q.empty() && x[0] > q.top()) {
        q.pop();
      }
      q.push(x[1]);
    }
    return q.size();
  }
};

signed main() {
  vector<vector<int>> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
  Solution sol = Solution();
  cout << sol.minGroups(intervals) << endl;

  return 0;
}