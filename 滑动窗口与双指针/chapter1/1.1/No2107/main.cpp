#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int shareCandies(vector<int> &candies, int k) {
    int n = candies.size();
    unordered_map<int, int> cnt;
    for (auto &x : candies) {
      ++cnt[x];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      if (i < k) {
        if (!--cnt[candies[i]]) {
          cnt.erase(candies[i]);
        }
      } else {
        ans = max(ans, (int)cnt.size());
        if (i == n) {
          break;
        }
        if (!--cnt[candies[i]]) {
          cnt.erase(candies[i]);
        }
        ++cnt[candies[i - k]];
      }
    }

    return ans;
  }
};

signed main() {
  vector<int> candies = {2, 4, 5};
  int k = 0;
  Solution sol;
  cout << sol.shareCandies(candies, k) << endl;

  return 0;
}