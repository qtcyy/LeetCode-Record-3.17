#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int similarPairs(vector<string> &words) {
    int n = words.size();
    unordered_map<string, int> mp;
    auto process = [](const string &s) {
      set<char> st(s.begin(), s.end());
      return string(st.begin(), st.end());
    };

    int ans = 0;
    for (auto &word : words) {
      string res = process(word);
      if (mp.contains(res)) {
        ans += mp[res];
      }
      mp[res]++;
    }
    return ans;
  }
};

signed main() {
  vector<string> words = {"aabb", "ab", "ba"};
  Solution sol = Solution();
  cout << sol.similarPairs(words) << endl;

  return 0;
}