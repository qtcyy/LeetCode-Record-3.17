#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool hasGroupsSizeX(vector<int> &deck) {
    unordered_map<int, int> cnt;
    for (auto &x : deck) {
      ++cnt[x];
    }
    int d = cnt.begin()->second;
    for (auto &[_, val] : cnt) {
      d = gcd(d, val);
    }
    return d >= 2;
  }
};

signed main() {
  vector<int> deck = {1, 2, 3, 4, 4, 3, 2, 1};
  Solution sol;
  cout << (sol.hasGroupsSizeX(deck) ? "true" : "false") << endl;

  return 0;
}