#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  long long beautifulSubarrays(vector<int> &nums) {
    int n = nums.size();
    int pre = 0;
    long long ans = 0;
    unordered_map<int, int> cnt{{0, 1}};
    for (int i = 0; i < n; i++) {
      pre ^= nums[i];
      if (cnt.contains(pre)) {
        ans += cnt[pre];
      }
      cnt[pre]++;
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {4, 3, 1, 2, 4};
  Solution sol = Solution();
  cout << sol.beautifulSubarrays(nums) << endl;

  return 0;
}