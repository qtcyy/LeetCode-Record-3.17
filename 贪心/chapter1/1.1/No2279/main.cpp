#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumBags(vector<int> &capacity, vector<int> &rocks,
                  int additionalRocks) {
    int n = capacity.size();
    vector<int> delta(n);
    for (int i = 0; i < n; i++) {
      delta[i] = capacity[i] - rocks[i];
    }
    ranges::sort(delta);
    int ans = 0;
    for (auto &x : delta) {
      additionalRocks -= x;
      if (additionalRocks >= 0) {
        ++ans;
      } else {
        break;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> capacity = {2, 3, 4, 5}, rocks = {1, 2, 4, 4};
  int additionalRocks = 2;
  Solution sol;
  cout << sol.maximumBags(capacity, rocks, additionalRocks) << endl;

  return 0;
}