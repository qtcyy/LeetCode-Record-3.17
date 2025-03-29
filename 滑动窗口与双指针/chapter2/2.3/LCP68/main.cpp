#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
  int beautifulBouquet(vector<int> &flowers, int cnt) {
    int n = flowers.size();
    unordered_map<int, int> mp;
    long long ans = 0;
    int left = 0;
    for (int i = 0; i < n; i++) {
      ++mp[flowers[i]];
      while (mp[flowers[i]] > cnt) {
        if (!--mp[flowers[left]]) {
          mp.erase(flowers[left]);
        }
        ++left;
      }
      ans = (ans + i - left + 1) % mod;
    }

    return ans;
  }
};

signed main() {
  vector<int> flowers = {5, 3, 3, 3};
  int cnt = 2;
  Solution sol;
  cout << sol.beautifulBouquet(flowers, cnt) << endl;

  return 0;
}