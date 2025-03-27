#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Finwick {
private:
  vector<int> sum;
  int n;

  inline int lowbit(int &x) { return x & (-x); }

public:
  Finwick(int n) : n(n), sum(n) {}

  inline void update(int i, int k) {
    while (i < n) {
      sum[i] += k;
      i += lowbit(i);
    }
  }

  inline int query(int i) {
    int res = 0;
    while (i) {
      res += sum[i];
      i -= lowbit(i);
    }
    return res;
  }
};

class Solution {
public:
  int reversePairs(vector<int> &record) {
    int n = record.size();
    vector<int> tmp = record;
    sort(tmp.begin(), tmp.end());
    for (int &num : record) {
      num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
    }
    Finwick f(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans += f.query(record[i] - 1);
      f.update(record[i], 1);
    }
    return ans;
  }
};

signed main() {
  vector<int> record = {9, 7, 5, 4, 6};
  Solution sol;
  cout << sol.reversePairs(record) << endl;

  return 0;
}