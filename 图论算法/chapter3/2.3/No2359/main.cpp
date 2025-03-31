#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int n = edges.size(), min_dis = n, ans = -1;
    auto calc = [&](int x) -> vector<int> {
      vector<int> dis(n, n);
      for (int d = 0; x >= 0 && dis[x] == n; x = edges[x]) {
        dis[x] = d++;
      }
      return dis;
    };
    auto d1 = calc(node1), d2 = calc(node2);
    for (int i = 0; i < n; i++) {
      int d = max(d1[i], d2[i]);
      if (d < min_dis) {
        min_dis = d;
        ans = i;
      }
    }
    return ans;
  }
};

signed main() {
  vector<int> edges = {2, 2, 3, -1};
  int node1 = 0, node2 = 1;
  Solution sol;
  cout << sol.closestMeetingNode(edges, node1, node2) << endl;

  return 0;
}