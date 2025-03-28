#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int countCompleteSubarrays(vector<int> &nums) {
    int n = nums.size();
    unordered_set<int> st;
    for (auto &x : nums) {
      st.insert(x);
    }
    int k = st.size();
    int left = 0, ans = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      ++cnt[nums[i]];
      while (cnt.size() >= k) {
        if (!--cnt[nums[left]]) {
          cnt.erase(nums[left]);
        }
        ++left;
      }
      ans += left;
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 3, 1, 2, 2};
  Solution sol;
  cout << sol.countCompleteSubarrays(nums) << endl;

  return 0;
}