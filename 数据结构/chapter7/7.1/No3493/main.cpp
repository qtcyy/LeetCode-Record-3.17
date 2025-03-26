#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f;
  int siz = 0;

  int find(int x) {
    if (f[x] == x) {
      return x;
    }
    return f[x] = find(f[x]);
  }

  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
      return;
    }
    f[x] = y;
    siz--;
  }

public:
  int numberOfComponents(vector<vector<int>> &properties, int k) {
    int n = properties.size();
    siz = n;
    f.resize(n);
    iota(f.begin(), f.end(), 0);
    vector<unordered_set<int>> recorder(n);
    for (int i = 0; i < n; i++) {
      recorder[i] =
          unordered_set<int>(properties[i].begin(), properties[i].end());
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        auto &a = recorder[i], &b = recorder[j];
        int cnt = 0;
        for (auto &x : a) {
          if (b.contains(x)) {
            ++cnt;
          }
        }
        if (cnt >= k) {
          merge(i, j);
        }
      }
    }
    return siz;
  }
};

signed main() {
  vector<vector<int>> properties = {{1, 2}, {1, 1}, {3, 4},
                                    {4, 5}, {5, 6}, {7, 7}};
  int k = 1;
  Solution sol;
  cout << sol.numberOfComponents(properties, k) << endl;

  return 0;
}