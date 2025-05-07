/*
 * @lc app=leetcode.cn id=3419 lang=cpp
 *
 * [3419] 图的最大边权的最小值
 */
#include <algorithm>
#include <cstring>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int s, to, next;
};
node que[N];

int head[N], dis[N];
int cnt = 1;

inline void add(int u, int v, int w) {
    que[cnt].s = w;
    que[cnt].to = v;
    que[cnt].next = head[u];
    head[u] = cnt++;
}

class Solution {
  public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        if (edges.size() < n - 1) {
            return -1;
        }
        memset(head, -1, sizeof(head));
        for (auto& p : edges) {
            add(p[1], p[0], p[2]);
        }
        memset(dis, 0x3f, sizeof(dis));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dis[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u])
                continue;
            for (int i = head[u]; i != -1; i = que[i].next) {
                int v = que[i].to;
                int new_d = max(d, que[i].s);
                if (dis[v] > new_d) {
                    dis[v] = new_d;
                    pq.emplace(dis[v], v);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dis[i]);

        return ans == inf ? -1 : ans;
    }
};
// @lc code=end
