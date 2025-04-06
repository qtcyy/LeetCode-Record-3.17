#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int fillCups(vector<int> &amount) {
    int ans = 0;
    while (true) {
      ranges::sort(amount);

      if (amount[1] == 0) {
        return ans + amount[2];
      }

      --amount[2];
      --amount[1];
      ++ans;
    }
  }
};

signed main() {
  Solution sol;
  vector<int> amount = {5, 4, 4};
  cout << sol.fillCups(amount) << endl;

  return 0;
}