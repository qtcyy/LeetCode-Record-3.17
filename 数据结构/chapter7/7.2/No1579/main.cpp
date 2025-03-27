#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;
  int sz1 = 0, sz2 = 0, n = 0;

  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
      return false;
    }
    f[x] = y;
    if (x > n) {
      --sz2;
    } else {
      --sz1;
    }
    return true;
  }

public:
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
    f.resize(n * 2);
    this->n = n;
    sz1 = n;
    sz2 = n;
    iota(f.begin(), f.end(), 0);
    int ans = 0;
    for (auto &edge : edges) {
      --edge[1];
      --edge[2];
      if (edge[0] == 3) {
        if (!merge(edge[1], edge[2])) {
          ++ans;
        } else {
          merge(edge[1] + n, edge[2] + n);
        }
      }
    }

    for (auto &edge : edges) {
      if (edge[0] == 1) {
        if (!merge(edge[1], edge[2])) {
          ++ans;
        }
      } else if (edge[0] == 2) {
        if (!merge(edge[1] + n, edge[2] + n)) {
          ++ans;
        }
      }
    }
    if (sz1 != 1 || sz2 != 1) {
      return -1;
    }

    return ans;
  }
};

signed main() {
  int n = 4;
  vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3},
                               {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
  Solution sol;
  cout << sol.maxNumEdgesToRemove(n, edges) << endl;

  return 0;
}