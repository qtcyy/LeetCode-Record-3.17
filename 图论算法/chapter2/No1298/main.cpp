#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes) {
    int n = status.size();
    queue<int> q;
    unordered_set<int> st;
    vector<bool> vis(n, false);
    int res = 0;
    auto bfs = [&]() {
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!vis[u] && status[u] == 1) {
          res += candies[u];
          vis[u] = 1;
          for (auto &b : containedBoxes[u]) {
            q.push(b);
          }
          for (auto &key : keys[u]) {
            status[key] = 1;
            if (!vis[key] && st.contains(key)) {
              q.push(key);
            }
          }
        } else {
          st.insert(u);
        }
      }
    };
    for (auto &b : initialBoxes) {
      st.insert(b);
      q.push(b);
    }
    bfs();

    return res;
  }
};

signed main() {
  vector<int> status = {1, 0, 1, 0}, candies = {7, 5, 4, 100};
  vector<vector<int>> keys = {{}, {}, {1}, {}},
                      containedBoxes = {{1, 2}, {3}, {}, {}};
  vector<int> initialBoxes = {0};
  Solution sol;
  cout << sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes)
       << endl;
  return 0;
}