#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxWeight(vector<int> &pizzas) {
    int n = pizzas.size() / 4;
    ranges::sort(pizzas, greater<>());
    int odd = (n + 1) / 2;
    long long ans = 0;
    for (int i = 0; i < odd; i++) {
      ans += pizzas[i];
    }
    for (int i = 0; i < n / 2; i++) {
      ans += pizzas[odd + i * 2 + 1];
    }
    return ans;
  }
};

signed main() {
  Solution sol;
  vector<int> pizzas = {1, 2, 3, 4, 5, 6, 7, 8};
  cout << sol.maxWeight(pizzas) << endl;

  return 0;
}