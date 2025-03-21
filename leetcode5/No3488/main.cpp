#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
    unordered_map<int, vector<int>> recorder;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      recorder[nums[i]].push_back(i);
    }
    for (auto &&[_, p] : recorder) {
      int i0 = p[0];
      p.insert(p.begin(), p.back() - n);
      p.push_back(i0 + n);
    }
    for (auto &i : queries) {
      auto &p = recorder[nums[i]];
      if (p.size() == 3) {
        i = -1;
      } else {
        int j = lower_bound(p.begin(), p.end(), i) - p.begin();
        i = min(i - p[j - 1], p[j + 1] - i);
      }
    }
    return queries;
  }
};

signed main() {
  vector<int> nums = {1, 3, 1, 4, 1, 3, 2}, queries = {0, 3, 5};
  Solution sol = Solution();
  vector<int> ans = sol.solveQueries(nums, queries);
  for (auto &x : ans) {
    cout << x << ' ';
  }

  return 0;
}