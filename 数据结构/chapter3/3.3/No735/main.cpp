#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> st;
    for (auto aster : asteroids) {
      bool alive = true;
      while (alive && aster < 0 && !st.empty() && st.back() > 0) {
        alive = st.back() < -aster; // aster 是否存在
        if (st.back() <= -aster) {  // 栈顶行星爆炸
          st.pop_back();
        }
      }
      if (alive) {
        st.push_back(aster);
      }
    }
    return st;
  }
};

signed main() {
  vector<int> asteroids = {-2, -1, 1, 2};
  Solution sol = Solution();
  vector<int> ans = sol.asteroidCollision(asteroids);
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << endl;

  return 0;
}