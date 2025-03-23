#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfPoints(vector<vector<int>> &nums) {
    vector<int> arr(105, 0);
    for (auto &pos : nums) {
      arr[pos[0]]++;
      arr[pos[1] + 1]--;
    }
    int ans = 0;
    for (int i = 1; i < 105; i++) {
      arr[i] += arr[i - 1];
      if (arr[i]) {
        ans++;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> nums = {{3, 6}, {1, 5}, {4, 7}};
  Solution sol = Solution();
  cout << sol.numberOfPoints(nums) << endl;

  return 0;
}