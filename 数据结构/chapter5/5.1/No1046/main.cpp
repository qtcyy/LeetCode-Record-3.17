#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq;
    for (auto &x : stones) {
      pq.push(x);
    }
    while (pq.size() >= 2) {
      int x = pq.top();
      pq.pop();
      int y = pq.top();
      pq.pop();
      if (x == y) {
        continue;
      } else {
        pq.push(x - y);
      }
    }
    if (pq.empty()) {
      return 0;
    }
    return pq.top();
  }
};

signed main() {
  vector<int> stones = {2, 2};
  Solution sol = Solution();
  cout << sol.lastStoneWeight(stones) << endl;

  return 0;
}