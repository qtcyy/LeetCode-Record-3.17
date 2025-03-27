#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;

  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]);
  }

  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      f[x] = y;
    }
  }

public:
  vector<bool> friendRequests(int n, vector<vector<int>> &restrictions,
                              vector<vector<int>> &requests) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);

    unordered_map<int, unordered_map<int, bool>> cant;
    for (auto &res : restrictions) {
      cant[res[0]][res[1]] = cant[res[1]][res[0]] = true;
    }
    vector<bool> ans;
    for (auto &req : requests) {
      int x = find(req[0]), y = find(req[1]);
      if (x == y) {
        ans.push_back(true);
        continue;
      }
      if (cant[x][y]) {
        ans.push_back(false);
        continue;
      }
      ans.push_back(true);
      if (cant[x].size() > cant[y].size()) {
        swap(x, y);
      }
      for (auto &[x0, _] : cant[x]) {
        int xx = find(x0);
        cant[y][xx] = cant[xx][y] = true;
      }
      f[x] = y;
    }
    return ans;
  }
};

class Solution2 {
private:
  vector<int> f;

  int find(int x) {
    if (f[x] == x)
      return x;
    return f[x] = find(f[x]); // 路径压缩
  }

public:
  vector<bool> friendRequests(int n, vector<vector<int>> &restrictions,
                              vector<vector<int>> &requests) {
    f.resize(n);
    iota(f.begin(), f.end(), 0);

    vector<unordered_map<int, bool>> cant(n);
    for (auto &res : restrictions) {
      cant[res[0]][res[1]] = true;
      cant[res[1]][res[0]] = true;
    }

    vector<bool> ans(requests.size(), false);
    for (int i = 0; i < requests.size(); i++) {
      int v = find(requests[i][0]), w = find(requests[i][1]);

      if (v == w) {
        ans[i] = true;
        continue;
      }

      bool canMerge = true;
      for (auto &[x, _] : cant[v]) {
        int xx = find(x);
        if (xx == w) {
          canMerge = false;
          break;
        }
      }

      for (auto &[x, _] : cant[w]) {
        int xx = find(x);
        if (xx == v) {
          canMerge = false;
          break;
        }
      }

      if (canMerge) {
        ans[i] = true;
        if (cant[v].size() > cant[w].size()) {
          swap(v, w);
        }

        for (auto &[x, _] : cant[v]) {
          int xx = find(x);
          cant[w][xx] = true;
          cant[xx][w] = true;
        }

        f[v] = w;
      }
    }

    return ans;
  }
};

signed main() {

  int n = 5;
  vector<vector<int>> restrictions = {{0, 1}, {1, 2}, {2, 3}},
                      requests = {{0, 4}, {1, 2}, {3, 1}, {3, 4}};
  Solution2 sol;
  vector<bool> ans = sol.friendRequests(n, restrictions, requests);
  for (auto x : ans) {
    cout << (x ? "True" : "False") << ' ';
  }
  cout << endl;

  return 0;
}