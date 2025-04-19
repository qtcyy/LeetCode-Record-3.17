/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 *
 * [2251] 花期内花的数目
 */
#include <algorithm>
#include <map>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                               vector<int> &people) {
    map<int, int> diff;
    for (auto &p : flowers) {
      ++diff[p[0]];
      --diff[p[1] + 1];
    }
    int n = people.size();
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    ranges::sort(id, [&](int &i, int &j) { return people[i] < people[j]; });
    int sum = 0;
    auto it = diff.begin();
    for (int i : id) {
      while (it != diff.end() && it->first <= people[i]) {
        sum += it++->second;
      }
      people[i] = sum;
    }
    return people;
  }
};
// @lc code=end
