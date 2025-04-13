#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSessions(vector<int> &tasks, int sessionTime) {
    int n = tasks.size();
    vector<int> sum(1 << n);
    for (int s = 1; s < 1 << n; s++) {
      for (int j = 0; j < n; j++) {
        if (s & (1 << j))
          sum[s] += tasks[j];
      }
    }
    vector<int> f(1 << n, INT_MAX);
    f[0] = 0;
    for (int s = 1; s < 1 << n; s++) {
      for (int i = s; i; i = s & (i - 1)) {
        if (sum[i] <= sessionTime) {
          f[s] = min(f[s], f[s ^ i] + 1);
        }
      }
    }
    return f.back();
  }
};

signed main() {
  vector<int> tasks = {3, 1, 3, 1, 1};
  int sessionTime = 8;
  Solution sol;
  cout << sol.minSessions(tasks, sessionTime) << endl;

  return 0;
}