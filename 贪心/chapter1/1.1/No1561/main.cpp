#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxCoins(vector<int> &piles) {
    ranges::sort(piles, [](int &a, int &b) { return a > b; });
    int n = piles.size() / 3;
    int ans = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
      ans += piles[i];
    }
    return ans;
  }
};

signed main() {
  vector<int> piles = {9, 8, 7, 6, 5, 1, 2, 3, 4};
  Solution sol;
  cout << sol.maxCoins(piles) << endl;

  return 0;
}