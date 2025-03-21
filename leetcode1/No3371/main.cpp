#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int getLargestOutlier(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    unordered_map<int, int> mp;
    for (auto &num : nums) {
      sum += num;
      mp[num]++;
    }
    cout << sum << endl;
    int ans = -1000;
    for (auto &num : nums) {
      int delta = sum - num;
      if (delta % 2 != 0)
        continue;
      delta /= 2;
      if (mp.contains(delta) && (mp[delta] > 1 || delta != num)) {
        ans = max(ans, num);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {6, -31, 50, -35, 41, 37, -42, 13};
  Solution sol = Solution();
  cout << sol.getLargestOutlier(nums) << endl;

  return 0;
}