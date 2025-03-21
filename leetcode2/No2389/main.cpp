#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    partial_sum(nums.begin(), nums.end(), nums.begin());
    for (auto &num : nums) {
      cout << num << ' ';
    }
    cout << endl;
    vector<int> res;
    for (auto &q : queries) {
      auto it = upper_bound(nums.begin(), nums.end(), q);
      res.push_back(it - nums.begin());
    }
    return res;
  }
};

signed main() {
  vector<int> nums = {2, 3, 4, 5}, queries = {1};
  Solution sol = Solution();
  vector<int> ans = sol.answerQueries(nums, queries);
  for (auto &num : ans) {
    cout << num << ' ';
  }

  return 0;
}