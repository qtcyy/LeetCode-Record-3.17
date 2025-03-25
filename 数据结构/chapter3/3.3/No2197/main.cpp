#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int getgcd(int x, int y) {
  if (y == 0) {
    return x;
  }
  return getgcd(y, x % y);
}

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int cur = nums[i];
      while (res.size() && getgcd(res.back(), cur) > 1) {
        int t = res.back();
        res.pop_back();
        int d = getgcd(t, cur);
        cur = d * (cur / d) * (t / d);
      }
      res.push_back(cur);
    }

    return res;
  }
};

signed main() {
  vector<int> nums = {287, 41, 49, 287, 899, 23, 23, 20677, 5, 825};
  Solution sol = Solution();
  vector<int> ans = sol.replaceNonCoprimes(nums);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}