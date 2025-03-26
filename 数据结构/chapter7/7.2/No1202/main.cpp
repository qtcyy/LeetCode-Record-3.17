#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
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
    if (x == y)
      return;
    f[x] = y;
  }

public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    int n = s.length();
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    for (auto &pi : pairs) {
      merge(pi[0], pi[1]);
    }
    vector<vector<char>> arr(n);
    vector<vector<int>> idx(n);
    for (int i = 0; i < n; i++) {
      int pos = find(i);
      arr[pos].push_back(s[i]);
      idx[pos].push_back(i);
    }
    vector<char> res(n);
    for (int i = 0; i < n; i++) {
      if (arr[i].empty()) {
        continue;
      }
      ranges::sort(arr[i]);
      int m = arr[i].size();
      for (int j = 0; j < m; j++) {
        res[idx[i][j]] = arr[i][j];
      }
    }
    return string(res.begin(), res.end());
  }
};

signed main() {
  string s = "dcab";
  vector<vector<int>> pairs = {{0, 3}, {1, 2}, {0, 2}};
  Solution sol;
  cout << sol.smallestStringWithSwaps(s, pairs) << endl;

  return 0;
}