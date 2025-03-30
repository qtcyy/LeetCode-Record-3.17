#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

struct node {
  int s, to, next;
};

class Solution {
private:
  vector<node> que;
  vector<int> head;
  int cnt = 1;

  inline void add(int u, int v, int w) {
    que[cnt].s = w;
    que[cnt].to = v;
    que[cnt].next = head[u];
    head[u] = cnt++;
  }

public:
  int minScore(int n, vector<vector<int>> &roads) {
    int m = roads.size();
    que.resize(m * 2 + 1);
    head.resize(n + 1, -1);
    vector<bool> vis(n);
    for (auto &p : roads) {
      int u = p[0], v = p[1], w = p[2];
      add(u, v, w);
      add(v, u, w);
    }
    int mn = INF;
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      for (int i = head[u]; i != -1; i = que[i].next) {
        int v = que[i].to;
        if (vis[v])
          continue;
        mn = min(mn, que[i].s);
        dfs(v);
      }
    };
    dfs(1);

    return mn;
  }
};

signed main() {
  int n = 4;
  vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
  Solution sol;
  cout << sol.minScore(n, roads) << endl;

  return 0;
}