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
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    f[x] = y;
  }

public:
  bool equationsPossible(vector<string> &equations) {
    f.resize(26);
    iota(f.begin(), f.end(), 0);
    for (auto &str : equations) {
      int x = str[0] - 'a', y = str.back() - 'a';
      if (str[1] == '=') {
        merge(x, y);
      }
    }
    for (auto &str : equations) {
      int x = str[0] - 'a', y = str.back() - 'a';
      if (str[1] == '!' && find(x) == find(y)) {
        return false;
      }
    }
    return true;
  }
};

signed main() {
  vector<string> strs{"c==c", "b==d", "x!=z"};
  Solution sol;
  cout << (sol.equationsPossible(strs) ? "Yes" : "No") << endl;

  return 0;
}