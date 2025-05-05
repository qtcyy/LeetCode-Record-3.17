/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
  public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int mul = 1, k = n;
        while (k) {
            mul <<= 1;
            k >>= 1;
        }
        mul--;
        return n ^ mul;
    }
};
// @lc code=end
