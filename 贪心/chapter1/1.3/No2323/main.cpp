#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumTime(vector<int> &jobs, vector<int> &workers) {
    ranges::sort(jobs);
    ranges::sort(workers);
    int n = jobs.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, (int)ceil(1.0 * jobs[i] / workers[i]));
    }
    return ans;
  }
};

signed main() {
  vector<int> jobs = {5, 2, 4}, workers = {1, 7, 5};
  Solution sol;
  cout << sol.minimumTime(jobs, workers) << endl;

  return 0;
}