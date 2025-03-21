#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> check(n - 1, 0);
    for (int i = 0; i < n - 1; ++i) {
      check[i] = ((nums[i] ^ nums[i + 1]) & 1);
    }
    partial_sum(check.begin(), check.end(), check.begin());
    vector<bool> res;
    for (auto &q : queries) {
      if (q[0] == q[1]) {
        res.push_back(true);
        continue;
      }
      int val = check[q[1] - 1] - (q[0] == 0 ? 0 : check[q[0] - 1]);
      if (val == q[1] - q[0]) {
        res.push_back(1);
      } else {
        res.push_back(0);
      }
    }
    return res;
  }
};

signed main() {
  vector<int> nums = {1};
  vector<vector<int>> queries = {{0, 0}};
  Solution sol = Solution();
  vector<bool> ans = sol.isArraySpecial(nums, queries);
  for (auto ck : ans) {
    cout << (ck ? "true" : "false") << endl;
  }

  return 0;
}