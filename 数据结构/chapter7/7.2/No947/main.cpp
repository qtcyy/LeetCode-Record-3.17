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

  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      f[x] = y;
    }
  }

public:
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
          merge(i, j);
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (find(i) == i) {
        ++sum;
      }
    }
    return n - sum;
  }
};

signed main() {
  vector<vector<int>> stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
  Solution sol;
  cout << sol.removeStones(stones) << endl;

  return 0;
}