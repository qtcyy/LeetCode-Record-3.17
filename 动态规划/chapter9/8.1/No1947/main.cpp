#include <bit>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxCompatibilitySum(vector<vector<int>> &students,
                          vector<vector<int>> &mentors) {
    int n = students.size(), m = students[0].size();
    vector<int> f(1 << n, 0);
    for (int s = 1; s < 1 << n; s++) {
      int i = popcount((unsigned)s) - 1;
      for (int j = 0; j < n; j++) {
        if (!(s & (1 << j)))
          continue;
        auto &st = students[i], &t = mentors[j];
        int tot = 0;
        for (int k = 0; k < m; k++)
          tot += 1 - (st[k] ^ t[k]);
        f[s] = max(f[s], f[s ^ (1 << j)] + tot);
      }
    }
    return f.back();
  }
};

signed main() {
  vector<vector<int>> students = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}},
                      mentors = {{1, 0, 0}, {0, 0, 1}, {1, 1, 0}};
  Solution sol;
  cout << sol.maxCompatibilitySum(students, mentors) << endl;

  return 0;
}