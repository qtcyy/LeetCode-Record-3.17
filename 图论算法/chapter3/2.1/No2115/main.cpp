#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    int n = recipes.size();
    unordered_map<string, int> degree(n);
    unordered_map<string, vector<string>> g;
    unordered_set<string> base(recipes.begin(), recipes.end());
    for (int i = 0; i < n; i++) {
      for (auto &p : ingredients[i]) {
        ++degree[recipes[i]];
        g[p].push_back(recipes[i]);
      }
    }
    queue<string> q;
    for (auto &s : supplies) {
      q.push(s);
    }
    vector<string> ord;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      ord.push_back(u);
      for (auto &v : g[u]) {
        if (!--degree[v]) {
          q.push(v);
        }
      }
    }
    vector<string> ans;
    for (auto &s : ord) {
      if (base.contains(s)) {
        ans.push_back(s);
      }
    }
    return ord;
  }
};

signed main() {
  vector<string> recipes = {"bread", "sandwich"};
  vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"}};
  vector<string> supplies = {"yeast", "flour", "meat"};
  Solution sol;
  auto ans = sol.findAllRecipes(recipes, ingredients, supplies);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}