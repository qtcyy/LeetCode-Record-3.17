#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    unordered_map<int, int> cnt;
    for (auto &x : arr) {
      ++cnt[x];
    }
    vector<pair<int, int>> g(cnt.begin(), cnt.end());
    ranges::sort(g, [](const auto &p1, const auto &p2) {
      return p1.second < p2.second;
    });
    int sum = 0;
    for (auto &&[val, count] : g) {
      k -= count;
      if (k < 0) {
        break;
      }
      ++sum;
    }
    return cnt.size() - sum;
  }
};

signed main() {
  vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
  int k = 3;
  Solution sol;
  cout << sol.findLeastNumOfUniqueInts(arr, k) << endl;

  return 0;
}