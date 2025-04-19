/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 *
 * [2251] 花期内花的数目
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                               vector<int> &people) {
    int n = flowers.size();
    vector<int> st(n), ed(n);
    for (int i = 0; i < n; i++) {
      st[i] = flowers[i][0];
      ed[i] = flowers[i][1];
    }
    ranges::sort(st);
    ranges::sort(ed);
    vector<int> ans;
    for (auto &x : people) {
      int res = (ranges::upper_bound(st, x) - st.begin()) -
                (ranges::lower_bound(ed, x) - ed.begin());
      ans.push_back(res);
    }
    return ans;
  }
};
// @lc code=end
