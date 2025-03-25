#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                    int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int n = tasks.size(), m = workers.size();
    auto check = [&](const int &mid) {
      multiset<int> ws;
      for (int i = m - mid; i < m; i++) {
        ws.insert(workers[i]);
      }
      int p = pills;
      for (int i = mid - 1; i >= 0; i--) {
        if (auto it = prev(ws.end()); *it >= tasks[i]) {
          ws.erase(it);
        } else {
          if (!p) {
            return false;
          }
          auto pos = ws.lower_bound(tasks[i] - strength);
          if (pos == ws.end()) {
            return false;
          }
          p--;
          ws.erase(pos);
        }
      }
      return true;
    };
    int l = -1, r = min(n, m) + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

signed main() {
  vector<int> tasks = {3, 2, 1}, workers = {0, 3, 3};
  int pills = 1, strength = 1;
  Solution sol = Solution();
  cout << sol.maxTaskAssign(tasks, workers, pills, strength) << endl;

  return 0;
}