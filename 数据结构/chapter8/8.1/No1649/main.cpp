#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Finwick {
private:
  vector<int> sum;
  int n;

  inline int lowbit(int &x) { return x & (-x); }

public:
  Finwick(int n) : n(n), sum(n) {}

  inline void update(int i, int k) {
    while (i < n) {
      sum[i] += k;
      i += lowbit(i);
    }
  }

  inline int query(int i) {
    int res = 0;
    while (i > 0) {
      res += sum[i];
      i -= lowbit(i);
    }
    return res;
  }
};

class Solution {
public:
  int createSortedArray(vector<int> &instructions) {
    int n = *max_element(instructions.begin(), instructions.end());
    Finwick f(n + 1);
    auto update = [&](const int &i, const int &val) { f.update(i, val); };
    vector<bool> vis(n + 1);
    long long ans = 0;
    for (auto &i : instructions) {
      ans = (ans + min(f.query(i - 1), f.query(n) - f.query(i))) % mod;
      if (!vis[i]) {
        update(i, 1);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> instructions = {1, 3, 3, 3, 2, 4, 2, 1, 2};
  Solution sol;
  cout << sol.createSortedArray(instructions) << endl;

  return 0;
}