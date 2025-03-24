#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size(), m = queries.size();
    auto check = [&](const int &mid) {
      vector<int> arr(n + 1);
      for (int i = 0; i < mid; i++) {
        arr[queries[i][0]] += queries[i][2];
        arr[queries[i][1] + 1] -= queries[i][2];
      }
      for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
      }
      for (int i = 0; i < n; i++) {
        if (arr[i] < nums[i]) {
          return false;
        }
      }
      return true;
    };
    int l = 0, r = m + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return r == m + 1 ? -1 : r;
  }
};

signed main() {
  vector<int> nums = {2, 0, 2};
  vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
  Solution sol = Solution();
  cout << sol.minZeroArray(nums, queries) << endl;

  return 0;
}