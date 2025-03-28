#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen) {
    int n = tiles.size();
    ranges::sort(tiles, [](auto &p1, auto &p2) { return p1[0] < p2[0]; });
    int left = 0, ans = 0, cover = 0;
    for (int i = 0; i < n; i++) {
      cover += tiles[i][1] - tiles[i][0] + 1;
      while (tiles[left][1] + carpetLen - 1 < tiles[i][1]) {
        cover -= tiles[left][1] - tiles[left][0] + 1;
        ++left;
      }
      int uncover = max(0, tiles[i][1] - carpetLen + 1 - tiles[left][0]);
      ans = max(ans, cover - uncover);
    }

    return ans;
  }
};

signed main() {
  vector<vector<int>> tiles = {{1, 5}, {10, 11}, {12, 18}, {20, 25}, {30, 32}};
  int carpetLen = 10;
  Solution sol;
  cout << sol.maximumWhiteTiles(tiles, carpetLen) << endl;

  return 0;
}