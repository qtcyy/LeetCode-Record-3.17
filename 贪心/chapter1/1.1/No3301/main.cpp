#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long maximumTotalSum(vector<int> &arr) {
    ranges::sort(arr, [](int &a, int &b) { return a > b; });
    int pre = arr[0] + 1;
    long long ans = 0;
    for (auto &x : arr) {
      pre = min(x, pre - 1);
      if (pre > 0) {
        ans += pre;
      } else {
        return -1;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> maximumHeight = {2, 3, 4, 3};
  Solution sol;
  cout << sol.maximumTotalSum(maximumHeight) << endl;

  return 0;
}