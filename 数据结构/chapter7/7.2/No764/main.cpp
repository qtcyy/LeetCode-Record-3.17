#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;

  int find(int x) {
    if (f[x] == x) {
      return x;
    }
    return f[x] = find(f[x]);
  }

  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      f[x] = y;
    }
  }

public:
  int minSwapsCouples(vector<int> &row) {
    int n = row.size();
    int tot = n / 2;
    f.resize(tot);
    iota(f.begin(), f.end(), 0);
    for (int i = 0; i < n; i += 2) {
      int x = row[i] / 2, y = row[i + 1] / 2;
      merge(x, y);
    }
    unordered_map<int, int> cnt;
    for (int i = 0; i < tot; i++) {
      ++cnt[find(i)];
    }
    int ans = 0;
    for (auto &&[_, x] : cnt) {
      ans += x - 1;
    }
    return ans;
  }
};

signed main() {
  vector<int> row = {0, 2, 1, 3};
  Solution sol;
  cout << sol.minSwapsCouples(row) << endl;

  return 0;
}