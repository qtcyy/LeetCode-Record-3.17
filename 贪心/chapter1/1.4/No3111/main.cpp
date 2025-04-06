#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
    ranges::sort(points, [](auto &a, auto &b) { return a[0] < b[0]; });
    int pos = -1, ans = 0;
    for (auto &p : points) {
      if (p[0] > pos) {
        pos = p[0] + w;
        ++ans;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3},
                                {4, 4}, {5, 5}, {6, 6}};
  int w = 2;
  Solution sol;
  cout << sol.minRectanglesToCoverPoints(points, w) << endl;

  return 0;
}