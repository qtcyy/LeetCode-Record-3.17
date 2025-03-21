#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long shiftDistance(string s, string t, vector<int> &nextCost,
                          vector<int> &previousCost) {
    partial_sum(nextCost.begin(), nextCost.end(), nextCost.begin());
    partial_sum(previousCost.begin(), previousCost.end(), previousCost.begin());
    nextCost.insert(nextCost.begin(), 0);
    previousCost.insert(previousCost.begin(), 0);
    int n = s.length();
    auto calc = [&](char x, char y) {
      int prev = 0, next = 0;
      int i = x - 'a' + 1, j = y - 'a' + 1;
      if (i > j) {
        prev = previousCost[i] - previousCost[j];
        next = nextCost.back() - nextCost[i] + nextCost[j];
      } else if (i < j) {
        prev = previousCost[i] + previousCost.back() - previousCost[j];
        next = nextCost[j] - nextCost[i];
      }

      cout << prev << ' ' << next << endl;
      return min(prev, next);
    };
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += calc(s[i], t[i]);
    }
    return ans;
  }
};

signed main() {
  string s = "abab", t = "baba";
  vector<int> nextCost = {100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
              previousCost = {1, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Solution sol = Solution();
  cout << sol.shiftDistance(s, t, nextCost, previousCost) << endl;

  return 0;
}