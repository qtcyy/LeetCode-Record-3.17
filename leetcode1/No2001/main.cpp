#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>> &rectangles) {
    map<double, int> mp;
    for (auto &row : rectangles) {
      mp[row[0] * 1.0 / row[1]]++;
    }
    long long ans = 0;
    for (auto &&[val, count] : mp) {
      if (count > 1) {
        ans += 1ll * count * (count - 1) / 2;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> rectangles = {{4, 8}, {3, 6}, {10, 20}, {15, 30}};

  Solution sol = Solution();
  cout << sol.interchangeableRectangles(rectangles) << endl;

  return 0;
}