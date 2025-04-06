#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos,
                                        vector<vector<int>> &friends, int id,
                                        int level) {
    int n = watchedVideos.size();
    vector<bool> vis(n, false);
    queue<int> q;
    auto bfs = [&](int s) {
      q.push(s);
      for (int i = 1; i <= level; i++) {
        int u = q.front();
        q.pop();
        if (vis[u])
          continue;
        vis[u] = 1;
        for (auto &v : friends[u]) {
          if (vis[v])
            continue;
          q.push(v);
        }
      }
    };
    bfs(id);
    unordered_map<string, int> cnt;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (auto &s : watchedVideos[u]) {
        ++cnt[s];
      }
    }

    vector<pair<string, int>> ans(cnt.begin(), cnt.end());
    ranges::sort(ans, [&](auto &p1, auto &p2) {
      return p1.second < p2.second ||
             (p1.second == p2.second && p1.first < p2.first);
    });
    vector<string> res;
    for (auto &&[str, _] : ans) {
      res.push_back(str);
    }
    return res;
  }
};

class Solution2 {
public:
  vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos,
                                        vector<vector<int>> &friends, int id,
                                        int level) {
    int n = watchedVideos.size();
    vector<bool> vis(n, false);
    vector<int> recorder;
    auto bfs = [&]() {
      queue<pair<int, int>> q;
      q.emplace(id, 0);
      while (!q.empty()) {
        auto [u, step] = q.front();
        q.pop();
        if (vis[u])
          continue;
        vis[u] = 1;
        if (step == level) {
          recorder.push_back(u);
        }
        for (auto &v : friends[u]) {
          if (vis[v])
            continue;
          q.emplace(v, step + 1);
        }
      }
    };
    bfs();
    unordered_map<string, int> cnt;
    for (auto &x : recorder) {
      for (auto &s : watchedVideos[x]) {
        ++cnt[s];
      }
    }
    vector<pair<string, int>> ans(cnt.begin(), cnt.end());
    ranges::sort(ans, [&](auto &p1, auto &p2) {
      return p1.second < p2.second ||
             (p1.second == p2.second && p1.first < p2.first);
    });
    vector<string> res;
    for (auto &&[str, _] : ans) {
      res.push_back(str);
    }
    return res;
  }
};

signed main() {
  vector<vector<string>> watchedVideos = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}};
  vector<vector<int>> friends = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
  int id = 0, level = 1;
  Solution2 sol;
  vector<string> ans =
      sol.watchedVideosByFriends(watchedVideos, friends, id, level);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}