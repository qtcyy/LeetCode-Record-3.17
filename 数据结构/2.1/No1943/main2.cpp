#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<long long>> splitPainting(vector<vector<int>> &segments) {
    map<int, long long> mp;
    for (auto &seg : segments) {
      int l = seg[0], r = seg[1], val = seg[2];
      mp[l] += val;
      mp[r] -= val;
    }
    vector<vector<long long>> ans;
    long long last = 0, color = 0;
    for (auto &[pos, val] : mp) {
      if (color) {
        ans.push_back({last, pos, color});
      }
      last = pos;
      color += val;
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> segments = {{1, 4, 5}, {1, 4, 7}, {4, 7, 1}, {4, 7, 11}};
  Solution sol = Solution();
  vector<vector<long long>> ans = sol.splitPainting(segments);
  for (auto &row : ans) {
    for (auto &x : row) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}