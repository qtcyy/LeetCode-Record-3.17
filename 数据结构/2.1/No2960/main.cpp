#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countTestedDevices(vector<int> &batteryPercentages) {
    int sum = 0;
    int ans = 0;
    for (auto &x : batteryPercentages) {
      if (x - sum > 0) {
        ++sum;
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> batteryPercentages = {1, 1, 2, 1, 3};
  Solution sol = Solution();
  cout << sol.countTestedDevices(batteryPercentages) << endl;

  return 0;
}