#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
    ranges::sort(queries, {}, [](const auto &q) { return q[0]; });
    int n = nums.size(), j = 0, sum = 0;
    vector<int> diff(n + 1, 0);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      sum += diff[i];
      while (j < queries.size() && queries[j][0] <= i) {
        pq.push(queries[i][1]);
        ++j;
      }
      while (sum < nums[i] && !pq.empty() && pq.top() >= i) {
        sum++;
        diff[pq.top() + 1]--;
        pq.pop();
      }
      if (sum < nums[i]) {
        return -1;
      }
    }
    return pq.size();
  }
};

signed main() {
  vector<int> nums = {2, 0, 2};
  vector<vector<int>> queries = {{0, 2}, {0, 2}, {1, 1}};
  Solution sol = Solution();
  cout << sol.maxRemoval(nums, queries) << endl;

  return 0;
}