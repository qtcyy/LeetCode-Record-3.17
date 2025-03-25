#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int catchMaximumAmountofPeople(vector<int> &team, int dist) {
    int n = team.size();
    vector<int> diff(n + 1, 0);
    int ghost = 0;
    for (int i = 0; i < n; i++) {
      if (!team[i]) {
        continue;
      }
      ghost++;
      int l = max(0, team[i] - dist);
      int r = min(n - 1, team[i] + dist);
      diff[l]++;
      diff[r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
      diff[i] += diff[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (diff[i] && !team[i]) {
        ans++;
      }
      cout << diff[i] << ' ';
    }
    cout << endl;
    cout << ans << ' ' << ghost << endl;
    return min(ans, ghost);
  }
};

signed main() {
  vector<int> team = {1, 1, 0, 1, 0, 1};
  int dist = 2;
  Solution sol = Solution();
  cout << sol.catchMaximumAmountofPeople(team, dist) << endl;

  return 0;
}