#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumCardPickup(vector<int> &cards) {
    int n = cards.size();
    unordered_map<int, stack<int>> mp;
    for (int i = n - 1; i >= 0; i--) {
      mp[cards[i]].push(i);
    }
    const int INF = 0x3f3f3f3f;
    int ans = INF;
    for (int i = 0; i < n; i++) {
      mp[cards[i]].pop();
      if (mp[cards[i]].empty())
        continue;
      ans = min(ans, mp[cards[i]].top() - i + 1);
    }
    return ans == INF ? -1 : ans;
  }
};

signed main() {
  vector<int> cards = {1, 0, 5, 3};
  Solution sol = Solution();
  cout << sol.minimumCardPickup(cards) << endl;

  return 0;
}