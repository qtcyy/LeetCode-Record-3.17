#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int connectSticks(vector<int> &sticks) {
    priority_queue<int, vector<int>, greater<>> pq;
    for (auto &x : sticks) {
      pq.push(x);
    }
    int ans = 0;
    while (pq.size() >= 2) {
      int x = pq.top();
      pq.pop();
      int y = pq.top();
      pq.pop();
      ans += x + y;
      pq.push(x + y);
    }
    return ans;
  }
};

signed main() {
  vector<int> sticks = {1, 8, 3, 5};
  Solution sol = Solution();
  cout << sol.connectSticks(sticks) << endl;

  return 0;
}