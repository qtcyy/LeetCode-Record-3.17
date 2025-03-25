#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> resultsArray(vector<vector<int>> &queries, int k) {
    priority_queue<int> pq;
    int n = queries.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
      int dist = abs(queries[i][0]) + abs(queries[i][1]);
      pq.push(dist);
      if (pq.size() > k) {
        pq.pop();
      }

      if (pq.size() == k) {
        ans[i] = pq.top();
      }
    }
    return ans;
  }
};

signed main() {
  vector<vector<int>> queries = {{1, 2}, {3, 4}, {2, 3}, {-3, 0}};
  int k = 2;
  Solution sol = Solution();
  vector<int> ans = sol.resultsArray(queries, k);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}