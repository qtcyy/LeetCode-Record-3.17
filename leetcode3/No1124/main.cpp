#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int longestWPI(vector<int> &hours) {
    int n = hours.size();
    hours.insert(hours.begin(), 0);
    for (int i = 1; i <= n; i++) {
      if (hours[i] > 8) {
        hours[i] = 1;
      } else {
        hours[i] = 0;
      }
      hours[i] += hours[i - 1];
    }
    int ans = 0;
    map<int, int> mp = {{0, 0}};
    for (int i = 1; i <= n; i++) {
      int val = hours[i] - i / 2;
      auto it = mp.lower_bound(val);
      if (it != mp.end()) {
        --it;
        ans = max(ans, i - it->second);
        cout << it->second << ' ';
      }
      if (!mp.contains(val)) {
        mp[val] = i;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> hours = {9, 9, 6, 0, 6, 6, 9};
  Solution sol = Solution();
  cout << sol.longestWPI(hours) << endl;

  return 0;
}