#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
    ranges::sort(asteroids);
    long long sum = mass;
    for (auto &x : asteroids) {
      if (sum >= x) {
        sum += x;
      } else {
        return false;
      }
    }
    return true;
  }
};

signed main() {
  int mass = 10;
  vector<int> asteroids = {3, 9, 19, 5, 21};
  Solution sol;
  cout << (sol.asteroidsDestroyed(mass, asteroids) ? "true" : "false") << endl;
  return 0;
}