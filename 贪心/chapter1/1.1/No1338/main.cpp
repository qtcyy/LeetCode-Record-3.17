#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int minSetSize(vector<int> &arr) {
    unordered_map<int, int> cnt;
    for (auto &x : arr) {
      ++cnt[x];
    }
    vector<pair<int, int>> recorder(cnt.begin(), cnt.end());
    ranges::sort(recorder,
                 [](auto &p1, auto &p2) { return p1.second > p2.second; });
    int n = arr.size(), sum = 0, ans = 0;
    n /= 2;
    for (auto &&[val, count] : recorder) {
      sum += count;
      ++ans;
      if (sum >= n) {
        break;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> arr = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
  Solution sol;
  cout << sol.minSetSize(arr) << endl;

  return 0;
}