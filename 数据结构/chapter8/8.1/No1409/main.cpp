#include <iostream>
#include <vector>
using namespace std;

class Finwick {
private:
  vector<int> sum;
  int n;

  inline int lowbit(int &x) { return x & (-x); }

public:
  Finwick(int n) : sum(n), n(n) {}

  inline void update(int i, int k) {
    while (i < n) {
      sum[i] += k;
      i += lowbit(i);
    }
  }

  inline int query(int i) {
    int res = 0;
    while (i > 0) {
      res += sum[i];
      i -= lowbit(i);
    }
    return res;
  }
};

class Solution {
public:
  vector<int> processQueries(vector<int> &queries, int m) {
    int n = queries.size();
    Finwick f(n + m + 1);
    vector<int> pos(m + 1);
    for (int i = 1; i <= m; i++) {
      f.update(i + n, 1);
      pos[i] = i + n;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int &cur = pos[queries[i]];
      ans[i] = f.query(cur) - 1;
      f.update(cur, -1);
      cur = n - i;
      f.update(cur, 1);
    }

    return ans;
  }
};

signed main() {
  vector<int> queries = {3, 1, 2, 1};
  int m = 5;
  Solution sol;
  vector<int> ans = sol.processQueries(queries, m);
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}