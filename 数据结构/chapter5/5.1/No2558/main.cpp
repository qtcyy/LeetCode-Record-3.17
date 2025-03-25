#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  long long pickGifts(vector<int> &gifts, int k) {
    priority_queue<int> pq;
    for (auto &x : gifts) {
      pq.push(x);
    }
    while (k--) {
      int val = pq.top();
      pq.pop();
      pq.push(sqrt(val));
    }
    long long ans = 0;
    while (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
    return ans;
  }
};

signed main() {
  vector<int> gifts = {25, 64, 9, 4, 100};
  int k = 4;
  Solution sol = Solution();
  cout << sol.pickGifts(gifts, k) << endl;

  return 0;
}