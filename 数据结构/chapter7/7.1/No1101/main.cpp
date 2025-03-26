#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;
  int sz = 0;

  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    f[x] = y;
    sz--;
  }

public:
  int earliestAcq(vector<vector<int>> &logs, int n) {
    f.resize(n);
    sz = n;
    iota(f.begin(), f.end(), 0);
    ranges::sort(logs, [](auto &p1, auto &p2) { return p1[0] < p2[0]; });
    for (auto log : logs) {
      merge(log[1], log[2]);
      if (sz == 1) {
        return log[0];
      }
    }
    return -1;
  }
};

signed main() {
  vector<vector<int>> logs = {
      {20190101, 0, 1}, {20190104, 3, 4}, {20190107, 2, 3}, {20190211, 1, 5},
      {20190224, 2, 4}, {20190301, 0, 3}, {20190312, 1, 2}, {20190322, 4, 5}};
  int N = 6;
  Solution sol;
  cout << sol.earliestAcq(logs, N) << endl;

  return 0;
}