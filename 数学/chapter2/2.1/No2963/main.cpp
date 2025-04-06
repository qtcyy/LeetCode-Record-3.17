#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int numberOfGoodPartitions(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> r;
    for (int i = 0; i < n; i++) {
      r[nums[i]] = i;
    }
    long long ans = 1;
    int mx = 0;
    for (int i = 0; i + 1 < n; i++) {
      mx = max(mx, r[nums[i]]);
      if (mx == i) {
        ans = (ans * 2) % mod;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {1, 2, 1, 3};
  Solution sol;
  cout << sol.numberOfGoodPartitions(nums) << endl;

  return 0;
}