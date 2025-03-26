#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  using PII = pair<int, int>;
  using LL = long long;

public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    int n = tasks.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](int i, int j) { return tasks[i][0] < tasks[i][0]; });
    priority_queue<PII, vector<PII>, greater<>> pq;
    LL timestamp = 0;
    int ptr = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
      if (pq.empty()) {
        timestamp = max(timestamp, (LL)tasks[idx[ptr]][0]);
      }
      while (ptr < n && tasks[idx[ptr]][0] <= timestamp) {
        pq.emplace(tasks[idx[ptr]][1], idx[ptr]);
        ++ptr;
      }
      auto &&[process, pos] = pq.top();
      timestamp += process;
      ans.push_back(pos);
      pq.pop();
    }

    return ans;
  }
};

signed main() {
  vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};

  Solution sol = Solution();
  vector<int> ans = sol.getOrder(tasks);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}