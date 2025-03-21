#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxDistance(vector<vector<int>> &arrays) {
    const int N = 0x3f3f3f3f;
    int minn = N, maxn = -N;
    int ans = -N;
    for (auto &row : arrays) {
      int temp_min = *min_element(row.begin(), row.end());
      int temp_max = *max_element(row.begin(), row.end());
      ans = max(ans, max(maxn - temp_min, temp_max - minn));
      minn = min(minn, temp_min);
      maxn = max(maxn, temp_max);
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> arrays = {{1, 4}, {0, 5}};
  Solution sol = Solution();
  cout << sol.maxDistance(arrays) << endl;

  return 0;
}