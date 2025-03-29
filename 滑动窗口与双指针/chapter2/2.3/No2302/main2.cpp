#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, long long k) {
    int n = nums.size();
    long long s = 0, ans = 0;
    int left = 0;
    for (int i = 0; i < n; i++) {
      s += nums[i];
      while (s * (i - left + 1) >= k) {
        s -= nums[left++];
      }
      ans += i - left + 1;
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {2, 1, 4, 3, 5};
  int k = 10;
  Solution sol;
  cout << sol.countSubarrays(nums, k) << endl;

  return 0;
}