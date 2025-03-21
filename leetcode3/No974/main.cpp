#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    // (arr[i]-arr[j-1])%k==0
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    for (int i = 1; i <= n; i++) {
      nums[i] += nums[i - 1];
    }
    map<int, int> cnt;
    cnt[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      nums[i] = (nums[i] % k + k) % k;
      if (cnt.contains(nums[i])) {
        ans += cnt[nums[i]];
      }
      ++cnt[nums[i]];
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {-1, 2, 9};
  int k = 2;
  Solution sol = Solution();
  cout << sol.subarraysDivByK(nums, k) << endl;

  return 0;
}