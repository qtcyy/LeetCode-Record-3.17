#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  long long minDamage(int power, vector<int> &damage, vector<int> &health) {
    int n = damage.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
      arr.emplace_back((health[i] - 1) / power + 1, damage[i]);
    }
    ranges::sort(arr, [](auto &p1, auto &p2) {
      return p1.first * p2.second < p1.second * p2.first;
    });
    long long ans = 0, s = 0;
    for (auto &&[k, d] : arr) {
      s += k;
      ans += s * d;
    }
    return ans;
  }
};

signed main() {
  int power = 4;
  vector<int> damage = {1, 2, 3, 4}, health = {4, 5, 6, 8};
  Solution sol;
  cout << sol.minDamage(power, damage, health) << endl;

  return 0;
}