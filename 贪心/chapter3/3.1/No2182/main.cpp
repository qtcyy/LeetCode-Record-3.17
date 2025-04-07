#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    int cnt[26]{};
    for (auto &ch : s) {
      ++cnt[ch - 'a'];
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 26; i++) {
      if (cnt[i])
        pq.emplace(i, cnt[i]);
    }
    string ans;
    while (pq.size()) {
      auto [ch, s] = pq.top();
      pq.pop();
      int rest = repeatLimit;
      while (s) {
        if (!rest) {
          if (pq.empty()) {
            return ans;
          }
          auto [ch2, s2] = pq.top();
          pq.pop();
          ans.push_back(ch2 + 'a');
          if (--s2) {
            pq.emplace(ch2, s2);
          }
          rest = repeatLimit;
        }
        ans.push_back(ch + 'a');
        --rest;
        --s;
      }
    }
    return ans;
  }
};

signed main() {
  string s = "cczazcc";
  int repeatLimit = 3;
  Solution sol;
  cout << sol.repeatLimitedString(s, repeatLimit) << endl;

  return 0;
}