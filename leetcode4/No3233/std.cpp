#include <cmath>
const int MX = 31622;
int pi[MX + 1];

auto init = [] {
  for (int i = 2; i <= MX; i++) {
    if (pi[i] == 0) { // i 是质数
      pi[i] = pi[i - 1] + 1;
      for (int j = i * i; j <= MX;
           j += i) { // 注：如果 MX 比较大，小心 i*i 溢出
        pi[j] = -1;  // 标记 i 的倍数为合数
      }
    } else {
      pi[i] = pi[i - 1];
    }
  }
  return 0;
}();

class Solution {
public:
  int nonSpecialCount(int l, int r) {
    return r - l + 1 - (pi[(int)sqrt(r)] - pi[(int)sqrt(l - 1)]);
  }
};
