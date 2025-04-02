#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int minIncrementForUnique(vector<int> &nums) {
    map<int, int> cnt;
    for (auto &x : nums) {
      ++cnt[x];
    }
    int ans = 0, cur = cnt.begin()->first;
    for (auto &&[x, count] : cnt) {
      cur = max(cur, x);
      int base = max(0, cur - x);
      ans += base * count;
      ans += (count - 1) * count / 2;
      cur += count;
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {3, 2, 1, 2, 1, 7};
  Solution sol;
  cout << sol.minIncrementForUnique(nums) << endl;

  return 0;
}