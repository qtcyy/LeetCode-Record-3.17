#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int countNicePairs(vector<int> &nums) {
    int n = nums.size();
    map<long long, int> mp;
    auto rev = [](int num) {
      long long res = 0;
      while (num) {
        res += num % 10;
        num /= 10;
        if (!num) {
          break;
        }
        res *= 10;
      }

      return res;
    };
    long long ans = 0;
    int mod = 1e9 + 7;
    for (int &num : nums) {
      long long sum = num - rev(num);
      cout << rev(num) << endl;
      if (mp.contains(sum)) {
        ans += mp[sum];
      }
      mp[sum]++;
    }
    return ans % mod;
  }
};

signed main() {
  vector<int> nums = {13, 10, 35, 24, 76};
  Solution sol = Solution();
  cout << sol.countNicePairs(nums) << endl;

  return 0;
}