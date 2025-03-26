#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    vector<int> cnt(n, 0);
    priority_queue<int, vector<int>, greater<>> idle;
    for (int i = 0; i < n; i++)
      idle.push(i);
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> using_;
    sort(meetings.begin(), meetings.end(),
         [](auto &p1, auto &p2) { return p1[0] < p2[0]; });
    for (auto &m : meetings) {
      long st = m[0], end = m[1], id;
      while (!using_.empty() && using_.top().first <= st) {
        idle.push(using_.top().second);
        using_.pop();
      }
      if (idle.empty()) {
        auto [e, i] = using_.top();
        using_.pop();
        end += e - st;
        id = i;
      } else {
        id = idle.top();
        idle.pop();
      }
      cnt[id]++;
      using_.emplace(end, id);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (cnt[i] > cnt[ans])
        ans = i;
    return ans;
  }
};

signed main() {
  int n = 3;
  vector<vector<int>> meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
  Solution sol = Solution();
  cout << sol.mostBooked(n, meetings) << endl;

  return 0;
}