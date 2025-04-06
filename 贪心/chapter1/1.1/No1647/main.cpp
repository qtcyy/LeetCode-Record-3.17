#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minDeletions(string s) {
    int cnt[26]{};
    for (auto &ch : s) {
      ++cnt[ch - 'a'];
    }
    vector<int> rec;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] > 0)
        rec.push_back(cnt[i]);
    }
    ranges::sort(rec);
    unordered_set<int> st;
    int ans = 0;
    for (int i = 0; i < rec.size(); i++) {
      while (rec[i] > 0 && st.contains(rec[i])) {
        --rec[i];
        ++ans;
      }
      if (rec[i] > 0) {
        st.insert(rec[i]);
      }
    }
    return ans;
  }
};

signed main() {
  string s = "aaabbbcc";
  Solution sol;
  cout << sol.minDeletions(s) << endl;

  return 0;
}