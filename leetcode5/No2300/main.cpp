#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    // spells[i]*potions[j]>=success
    // spells[i]>=ceil(success/potions[i])
    sort(potions.begin(), potions.end());
    vector<int> pairs;
    for (auto &x : spells) {
      int val = ceil(1.0 * success / x);
      auto it = lower_bound(potions.begin(), potions.end(), val);
      if (it == potions.end()) {
        pairs.push_back(0);
      } else {
        pairs.push_back((int)(potions.end() - it));
      }
    }
    return pairs;
  }
};

signed main() {
  Solution sol = Solution();
  vector<int> spells = {5, 1, 3}, potions = {1, 2, 3, 4, 5};
  long long success = 7;
  vector<int> ans = sol.successfulPairs(spells, potions, success);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}