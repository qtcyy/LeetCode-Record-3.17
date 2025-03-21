#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> findMatrix(vector<int> &nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    int maxsize = 0;
    for (auto &num : nums) {
      mp[num]++;
      maxsize = max(maxsize, mp[num]);
    }
    vector<vector<int>> ans(maxsize);
    for (auto &&[num, count] : mp) {
      for (int i = 0; i < count; i++) {
        ans[i].push_back(num);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 3, 4, 1, 2, 3, 1};
  Solution sol = Solution();
  vector<vector<int>> ans = sol.findMatrix(nums);
  for (auto &row : ans) {
    for (auto &num : row) {
      cout << num << ' ';
    }
    cout << endl;
  }

  return 0;
}