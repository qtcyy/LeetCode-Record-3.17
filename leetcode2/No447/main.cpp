#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int ans = 0;
    for (auto &p1 : points) {
      unordered_map<int, int> cnt;
      for (auto &p2 : points) {
        int dist = (p1[0] - p2[0]) * (p1[0] - p2[0]) +
                   (p1[1] - p2[1]) * (p1[1] - p2[1]);
        ans += cnt[dist]++ * 2;
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
  Solution sol = Solution();
  cout << sol.numberOfBoomerangs(points) << endl;

  return 0;
}