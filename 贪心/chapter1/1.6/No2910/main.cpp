#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minGroupsForValidAssignment(vector<int> &nums) {
    unordered_map<int, int> cnt;
    for (int x : nums) {
      cnt[x]++;
    }
    int k =
        min_element(cnt.begin(), cnt.end(), [](const auto &a, const auto &b) {
          return a.second < b.second;
        })->second;
    for (;; k--) {
      int ans = 0;
      for (auto &[_, c] : cnt) {
        if (c % k && (c % (k + 1) && c % (k + 1) != k)) {
          ans = 0;
          break;
        }
        ans += (c + k) / (k + 1);
      }
      if (ans) {
        return ans;
      }
    }
    return 0;
  }
};

signed main() {
  vector<int> balls = {3, 2, 3, 2, 3};
  Solution sol;
  cout << sol.minGroupsForValidAssignment(balls) << endl;

  return 0;
}