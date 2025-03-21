#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    nums.insert(nums.begin(), 0);
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      nums[i] += nums[i - 1];
      //   cout << nums[i] << ' ';
    }
    // cout << endl;
    map<int, int> cnt;
    cnt[0] = 1;
    // nums[i]-nums[j-1]==goal
    // => nums[i]-goal=nums[j-1]
    int ans = 0;
    for (int i = 1; i < n; i++) {
      int val = nums[i] - goal;
      if (cnt.contains(val)) {
        ans += cnt[val];
      }
      ++cnt[nums[i]];
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 0, 1, 0, 1};
  int goal = 2;
  Solution sol = Solution();
  cout << sol.numSubarraysWithSum(nums, goal) << endl;

  return 0;
}