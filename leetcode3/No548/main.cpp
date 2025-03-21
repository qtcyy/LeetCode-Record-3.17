#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool splitArray(vector<int> &nums) {
    if (nums.size() < 7)
      return false;
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    vector<int> pre_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pre_sum[i] = pre_sum[i - 1] + nums[i];
    }
    for (int j = 4; j <= n - 3; j++) {
      unordered_set<int> st;
      for (int i = 1; i < j - 1; i++) {
        if (pre_sum[i - 1] == pre_sum[j - 1] - pre_sum[i]) {
          st.insert(pre_sum[i - 1]);
        }
      }
      if (st.empty()) {
        continue;
      }
      for (int k = j + 2; k < n; k++) {
        if (pre_sum[k - 1] - pre_sum[j] == pre_sum[n] - pre_sum[k] &&
            st.contains(pre_sum[k - 1] - pre_sum[j])) {
          return true;
        }
      }
    }
    return false;
  }
};

signed main() {
  vector<int> nums = {0, -3, 10, -10, -8, -7, 5, -7, 5, -3};
  Solution sol = Solution();
  cout << sol.splitArray(nums) << endl;

  return 0;
}