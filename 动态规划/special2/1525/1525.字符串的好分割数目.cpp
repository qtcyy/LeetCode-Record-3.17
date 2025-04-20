/*
 * @lc app=leetcode.cn id=1525 lang=cpp
 *
 * [1525] 字符串的好分割数目
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int numSplits(string s) {
    int n = s.length();
    vector<int> pre(n), suf(n);
    unordered_set<char> st;
    for (int i = 0; i < n; i++) {
      st.insert(s[i]);
      pre[i] = st.size();
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
      st.insert(s[i]);
      suf[i] = st.size();
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += (pre[i] == suf[i + 1]);
    }
    return ans;
  }
};
// @lc code=end
