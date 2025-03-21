#include <iostream>
#include <map>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    map<int, int> mp;
    for (int i = 0; i < position.size(); i++) {
      mp.insert(make_pair(position[i], speed[i]));
    }
    stack<double> st;
    for (auto &&[p, s] : mp) {
      double time = (target - p) * 1.0 / s;
      while (!st.empty() && st.top() <= time) {
        st.pop();
      }
      st.push(time);
    }

    return st.size();
  }
};

signed main() {
  int target = 12;
  vector<int> position = {10, 8, 0, 5, 3};
  vector<int> speed = {2, 4, 1, 1, 3};
  Solution *sol = new Solution();
  int ans = sol->carFleet(target, position, speed);
  delete sol;
  cout << ans << endl;

  return 0;
}