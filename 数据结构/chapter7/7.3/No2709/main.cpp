#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  const int N = 1e5;
  vector<int> f;
  int sz = 0;
  unordered_map<int, vector<int>> cnt;

  void pre(int mx) {
    vector<bool> is_prime(N + 5);
    for (int i = 2; i <= mx; i++) {
      if (!is_prime[i]) {
        for (int j = i; j <= mx; j += i) {
          is_prime[j] = 1;
          cnt[j].push_back(i);
        }
      }
    }
  }

  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
      return;
    }
    f[x] = y;
  }

public:
  bool canTraverseAllPairs(vector<int> &nums) {
    int n = nums.size();
    int mx = *max_element(nums.begin(), nums.end());
    if (n == 1) {
      return true;
    }
    f.resize(N);
    iota(f.begin(), f.end(), 0);
    pre(mx);
    for (auto &x : nums) {
      if (x == 1) {
        return false;
      }
      for (auto &j : cnt[x]) {
        merge(x, j);
      }
    }
    unordered_set<int> sum;
    for (auto &x : nums) {
      sum.insert(find(x));
    }
    return sum.size() == 1;
  }
};

signed main() {
  vector<int> nums = {4, 3, 12, 8};
  Solution sol;
  cout << sol.canTraverseAllPairs(nums) << endl;

  return 0;
}