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
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    f[x] = y;
  }

public:
  Solution() : f(26) { iota(f.begin(), f.end(), 0); }

  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.length();
    for (int i = 0; i < n; i++) {
      merge(s1[i] - 'a', s2[i] - 'a');
    }
    vector<int> mn(26, 30);
    for (int i = 0; i < 26; i++) {
      int cur = find(i);
      mn[cur] = min(mn[cur], i);
    }
    vector<vector<char>> arr(26);
    int m = baseStr.length();
    string ans;
    for (int i = 0; i < m; i++) {
      int val = baseStr[i] - 'a';
      ans.push_back(mn[find(val)] + 'a');
    }
    return ans;
  }
};

signed main() {
  string s1 = "parker", s2 = "morris", baseStr = "parser";
  Solution sol;
  cout << sol.smallestEquivalentString(s1, s2, baseStr) << endl;

  return 0;
}