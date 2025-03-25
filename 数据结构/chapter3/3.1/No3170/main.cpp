#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  string clearStars(string s) {
    int n = s.length();
    priority_queue<pair<char, int>, vector<pair<char, int>>,
                   less<pair<char, int>>>
        pq;
    unordered_set<int> filter;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        filter.insert(i);
        if (!pq.empty()) {
          auto [_, pos] = pq.top();
          filter.insert(pos);
          pq.pop();
        }
      } else {
        pq.push(make_pair(-s[i], i));
      }
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
      if (!filter.contains(i)) {
        ans += s[i];
      }
    }
    return ans;
  }
};

signed main() {
  string s = "aaba*";
  Solution sol = Solution();
  cout << sol.clearStars(s) << endl;

  return 0;
}