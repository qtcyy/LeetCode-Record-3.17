#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minIncrements(int n, vector<int> &cost) {
    int ans = 0;
    for (int i = n / 2; i > 0; i--) {
      ans += abs(cost[i * 2] - cost[i * 2 - 1]);
      cost[i - 1] += max(cost[i * 2 - 1], cost[i * 2]);
    }
    return ans;
  }
};

signed main() {
  int n = 7;
  vector<int> cost = {1, 5, 2, 2, 3, 3, 1};
  Solution sol;
  cout << sol.minIncrements(n, cost) << endl;

  return 0;
}