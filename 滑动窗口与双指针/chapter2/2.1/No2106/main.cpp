#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int n = fruits.size();
    int left = lower_bound(fruits.begin(), fruits.end(), startPos - k,
                           [](const auto &a, int b) { return a[0] < b; }) -
               fruits.begin();
    int right = left, s = 0;
    for (; right < n && fruits[right][0] <= startPos; right++) {
      s += fruits[right][1];
    }
    int ans = s;
    for (; right < n && fruits[right][0] <= startPos + k; right++) {
      s += fruits[right][1];
      while (fruits[right][0] * 2 - fruits[left][0] - startPos > k &&
             fruits[right][0] - fruits[left][0] * 2 + startPos > k) {
        s -= fruits[left++][1];
      }
      ans = max(ans, s);
    }

    return ans;
  }
};

signed main() {
  vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
  int startPos = 5, k = 4;
  Solution sol;
  cout << sol.maxTotalFruits(fruits, startPos, k) << endl;

  return 0;
}