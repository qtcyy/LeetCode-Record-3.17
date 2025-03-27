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
    if (x != y) {
      f[x] = y;
    }
  }

public:
  int numSimilarGroups(vector<string> &strs) {
    auto check = [](const string &s1, const string &s2) {
      int n = s1.length();
      if (n != s2.length()) {
        return false;
      }
      int sum = 0;
      for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
          ++sum;
        }
      }
      return sum <= 2;
    };
    int n = strs.size();
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (check(strs[i], strs[j])) {
          merge(i, j);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (find(i) == i)
        ++ans;
    }
    return ans;
  }
};

signed main() {
  vector<string> strs = {"tars", "rats", "arts", "star"};
  Solution sol;
  cout << sol.numSimilarGroups(strs) << endl;

  return 0;
}