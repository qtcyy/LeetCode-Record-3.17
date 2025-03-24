#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    unordered_set<int> cnt;
    int mx = 0;
    for (auto &x : target) {
      cnt.insert(x);
      mx = max(mx, x);
    }
    vector<string> ans;
    for (int i = 1; i <= mx; i++) {
      if (cnt.contains(i)) {
        ans.push_back("Push");
      } else {
        ans.push_back("Push");
        ans.push_back("Pop");
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> target = {1, 3};
  int n = 3;
  Solution sol = Solution();
  vector<string> ans = sol.buildArray(target, n);
  for (auto &x : ans) {
    cout << x << endl;
  }

  return 0;
}