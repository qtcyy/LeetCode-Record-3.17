#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minProcessingTime(vector<int> &processorTime, vector<int> &tasks) {
    ranges::sort(processorTime);
    ranges::sort(tasks, greater());
    int n = processorTime.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, processorTime[i] + tasks[4 * i]);
    }
    return ans;
  }
};

signed main() {
  vector<int> processorTime = {8, 10}, tasks = {2, 2, 3, 1, 8, 7, 4, 5};
  Solution sol;
  cout << sol.minProcessingTime(processorTime, tasks) << endl;

  return 0;
}