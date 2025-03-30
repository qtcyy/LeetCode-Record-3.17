#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;

  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

  inline void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      f[x] = y;
    }
  }

public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    int m = connections.size();
    if (m < n - 1) {
      return -1;
    }
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    for (auto &p : connections) {
      merge(p[0], p[1]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (find(i) == i) {
        ++sum;
      }
    }
    return sum - 1;
  }
};

signed main() {
  int n = 6;
  vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

  Solution sol;
  cout << sol.makeConnected(n, connections) << endl;

  return 0;
}