#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  long long countGood(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    int left = 0;
    long long s = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      s += cnt[nums[i]]++;
      while (s >= k) {
        s -= --cnt[nums[left++]];
      }
      ans += left;
    }

    return ans;
  }
};

signed main() {
  vector<int> nums = {3, 1, 4, 3, 2, 2, 4};
  int k = 2;
  Solution sol;
  cout << sol.countGood(nums, k) << endl;

  return 0;
}