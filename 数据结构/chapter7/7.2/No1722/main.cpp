#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
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
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    f[x] = y;
  }

public:
  int minimumHammingDistance(vector<int> &source, vector<int> &target,
                             vector<vector<int>> &allowedSwaps) {
    int n = source.size();
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    for (auto &p : allowedSwaps) {
      merge(p[0], p[1]);
    }
    unordered_map<int, unordered_map<int, int>> recorder1, recorder2;
    for (int i = 0; i < n; i++) {
      int pos = find(i);
      ++recorder1[pos][source[i]];
      ++recorder2[pos][target[i]];
    }
    int ans = 0;
    for (auto &&[pos, mp] : recorder2) {
      for (auto &&[num, cnt] : mp) {

        ans += max(cnt - recorder1[pos][num], 0);
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> source = {1, 2, 3, 4}, target = {2, 1, 4, 5};
  vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};
  Solution sol;
  cout << sol.minimumHammingDistance(source, target, allowedSwaps) << endl;

  return 0;
}