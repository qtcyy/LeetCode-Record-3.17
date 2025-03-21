#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int n = values.size();
    int maxn = values[0], ans = 0;
    for (int i = 1; i < n; i++) {
      ans = max(ans, maxn + values[i] - i);
      maxn = max(maxn, values[i] + i);
    }
    return ans;
  }
};

signed main() {
  vector<int> values = {1, 3, 5};
  Solution sol = Solution();
  cout << sol.maxScoreSightseeingPair(values) << endl;

  return 0;
}