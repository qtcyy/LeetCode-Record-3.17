#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  unordered_map<string, priority_queue<string, vector<string>, greater<>>> vec;
  vector<string> stk;

  void dfs(const string &u) {
    while (vec.contains(u) && vec[u].size() > 0) {
      string v = vec[u].top();
      vec[u].pop();
      dfs(move(v));
    }
    stk.emplace_back(u);
  }

public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    for (auto &p : tickets) {
      vec[p[0]].emplace(p[1]);
    }
    dfs("JFK");

    reverse(stk.begin(), stk.end());
    return stk;
  }
};

signed main() {
  vector<vector<string>> tickets = {
      {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  Solution sol;
  auto ans = sol.findItinerary(tickets);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}