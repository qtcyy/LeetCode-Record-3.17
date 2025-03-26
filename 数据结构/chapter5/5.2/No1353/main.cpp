#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 5;

class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    vector<vector<int>> time(N);
    for (auto &event : events) {
      time[event[0]].push_back(event[1]);
    }
    priority_queue<int, vector<int>, greater<>> pq;
    int ans = 0;
    for (int i = 0; i < N; i++) {
      for (auto end : time[i]) {
        pq.push(end);
      }

      while (pq.size() && pq.top() < i) {
        pq.pop();
      }

      if (pq.size()) {
        pq.pop();
        ans++;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
  Solution sol = Solution();
  cout << sol.maxEvents(events) << endl;

  return 0;
}