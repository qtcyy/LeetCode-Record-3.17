#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    priority_queue<int> pq;
    for (auto &x : piles) {
      pq.push(x);
    }
    while (k--) {
      int val = pq.top();
      pq.pop();
      val -= val / 2;
      pq.push(val);
    }
    int ans = 0;
    while (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }

    return ans;
  }
};

signed main() {
  vector<int> piles = {4, 3, 6, 7};
  int k = 3;
  Solution sol = Solution();
  cout << sol.minStoneSum(piles, k) << endl;

  return 0;
}