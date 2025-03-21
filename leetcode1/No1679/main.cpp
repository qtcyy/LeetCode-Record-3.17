#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    int n = nums.size();
    map<int, int> mp;
    for (auto &num : nums) {
      if (num >= k)
        continue;
      mp[num]++;
    }
    int ans = 0;
    for (auto &num : nums) {
      if (num >= k || !mp.contains(num))
        continue;
      if (mp.contains(k - num) && mp[num]) {
        mp[num]--;
        if (mp[k - num] > 0) {
          mp[k - num]--;
          ans++;
        }
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {4, 4, 1, 3, 1, 3, 2, 2, 5, 5, 1, 5, 2, 1, 2, 3, 5, 4};
  int k = 2;
  Solution sol = Solution();
  cout << sol.maxOperations(nums, k) << endl;

  return 0;
}