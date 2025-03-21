#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxK(vector<int> &nums) {
    int ans = -1;
    unordered_set<int> st;
    for (auto &num : nums) {
      if (num <= 0) {
        st.insert(num);
      }
    }
    for (auto &num : nums) {
      if (num >= 0 && st.contains(-num)) {
        ans = max(ans, num);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {-1, 10, 6, 7, -7, 1};
  Solution sol = Solution();
  cout << sol.findMaxK(nums) << endl;

  return 0;
}