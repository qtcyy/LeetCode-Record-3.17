#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    int mx = *max_element(nums.begin(), nums.end());
    int left = 0, cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cnt += (nums[i] == mx);
      while (cnt >= k) {
        cnt -= (nums[left++] == mx);
      }
      ans += left;
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 3, 2, 3, 3};
  int k = 2;
  Solution sol;
  cout << sol.countSubarrays(nums, k) << endl;

  return 0;
}