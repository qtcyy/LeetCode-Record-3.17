#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int brightestPosition(vector<vector<int>> &lights) {
    map<int, int> mp;
    for (auto &light : lights) {
      mp[light[0] - light[1]]++;
      mp[light[0] + light[1] + 1]--;
    }
    int ans = 0, mx = 0, sum = 0;
    for (auto &&[pos, val] : mp) {
      sum += val;
      if (sum > mx) {
        mx = sum;
        ans = pos;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> lights = {{-3, 2}, {1, 2}, {3, 3}};
  Solution sol = Solution();
  cout << sol.brightestPosition(lights) << endl;

  return 0;
}