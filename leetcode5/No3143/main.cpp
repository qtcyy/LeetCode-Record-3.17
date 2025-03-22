#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxPointsInsideSquare(vector<vector<int>> &points, string s) {
    int n = points.size();
    int ans = 0;
    auto check = [&](const int &mid) {
      unordered_set<char> recorder;
      for (int i = 0; i < n; i++) {
        if (abs(points[i][0]) <= mid && abs(points[i][1]) <= mid) {
          if (recorder.contains(s[i])) {
            return false;
          }
          recorder.insert(s[i]);
        }
      }
      ans = recorder.size();
      return true;
    };
    int mx = 0;
    for (auto &point : points) {
      mx = max({mx, abs(point[0]), abs(point[1])});
    }
    int l = -1, r = mx + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> points = {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}};
  string s = "abdca";
  Solution sol = Solution();
  cout << sol.maxPointsInsideSquare(points, s) << endl;

  return 0;
}