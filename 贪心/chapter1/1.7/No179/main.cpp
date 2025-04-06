#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      int x = nums[i];
      vector<int> tmp;
      while (x) {
        tmp.push_back(x % 10);
        x /= 10;
      }
      reverse(tmp.begin(), tmp.end());
      a[i] = std::move(tmp);
    }
    ranges::sort(a, [](auto &x, auto &y) {
      if (x.size() <= y.size()) {
        int n = x.size();

        for (int i = 0; i < n; i++) {
          if (x[i] > y[i]) {
            return true;
          } else if (x[i] < y[i]) {
            return false;
          }
        }
        int base = x.back(), m = y.size();
        for (int i = n; i < m; i++) {
          if (base > y[i]) {
            return true;
          } else if (base < y[i]) {
            return false;
          }
        }
      } else {
        int n = y.size();

        for (int i = 0; i < n; i++) {
          if (x[i] > y[i]) {
            return true;
          } else if (x[i] < y[i]) {
            return false;
          }
        }
        int base = y.back(), m = x.size();
        for (int i = n; i < m; i++) {
          if (x[i] > base) {
            return true;
          } else if (x[i] < base) {
            return false;
          }
        }
      }

      return x.size() > y.size();
    });
    string ans;
    for (auto &p : a) {
      for (auto &x : p) {
        ans.push_back(x + '0');
      }
    }
    return ans;
  }
};

class Solution2 {
public:
  string largestNumber(vector<int> &nums) {
    ranges::sort(nums, [](auto &a, auto &b) {
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    if (nums[0] == 0) {
      return "0";
    }
    string res = "";
    for (auto &x : nums) {
      res += to_string(x);
    }
    return res;
  }
};

signed main() {
  vector<int> nums = {3, 30, 34, 5, 9};
  Solution2 sol;
  cout << sol.largestNumber(nums) << endl;

  return 0;
}