#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    ranges::sort(boxTypes, [](auto &p1, auto &p2) { return p1[1] > p2[1]; });
    int ans = 0;
    for (auto &p : boxTypes) {
      if (p[0] <= truckSize) {
        truckSize -= p[0];
        ans += p[0] * p[1];
      } else {
        ans += p[1] * truckSize;
        break;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
  int truckSize = 4;
  Solution sol;
  cout << sol.maximumUnits(boxTypes, truckSize) << endl;
  return 0;
}