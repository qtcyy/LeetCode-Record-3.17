#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int maxGoodNumber(vector<int> &nums) {
    vector<string> a;
    for (auto x : nums) {
      string tmp = "";
      while (x) {
        if (x & 1) {
          tmp += '1';
        } else {
          tmp += '0';
        }
        x >>= 1;
      }
      reverse(tmp.begin(), tmp.end());
      a.push_back(tmp);
    }
    ranges::sort(a, [](auto &x, auto &y) { return x + y > y + x; });
    string res = "";
    for (auto &s : a) {
      res += s;
    }
    int m = res.length();
    int ans = 0, p = 1;
    for (int i = m - 1; i >= 0; i--) {
      if (res[i] == '1') {
        ans += p;
      }
      p <<= 1;
    }
    return ans;
  }
};

signed main() {
  vector<int> nums = {2, 8, 16};
  Solution sol;
  cout << sol.maxGoodNumber(nums) << endl;

  return 0;
}