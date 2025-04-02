#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    ranges::sort(costs);
    int ans = 0;
    for (auto &x : costs) {
      coins -= x;
      if (coins >= 0) {
        ++ans;
      } else {
        break;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> costs = {1, 3, 2, 4, 1};
  int coins = 7;
  Solution sol;
  cout << sol.maxIceCream(costs, coins) << endl;

  return 0;
}