#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int meetRequirement(int n, vector<vector<int>> &lights,
                      vector<int> &requirement) {
    vector<int> diff(n + 1, 0);
    for (auto &light : lights) {
      int l = max(0, light[0] - light[1]);
      int r = min(n - 1, light[0] + light[1]);
      diff[l]++;
      diff[r + 1]--;
    }
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      sum += diff[i];
      if (sum >= requirement[i]) {
        ans++;
      }
    }
    return ans;
  }
};

signed main() {
  int n = 5;
  vector<vector<int>> lights = {{0, 1}, {2, 1}, {3, 2}};
  vector<int> requirement = {0, 2, 1, 4, 1};
  Solution sol = Solution();
  cout << sol.meetRequirement(n, lights, requirement) << endl;

  return 0;
}