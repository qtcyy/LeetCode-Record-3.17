/*
 * @lc app=leetcode.cn id=2527 lang=golang
 *
 * [2527] 查询数组异或美丽值
 */
package main

// @lc code=start
func xorBeauty(nums []int) (ans int) {
	ans = 0
	for _, x := range nums {
		ans ^= x
	}
	return
}

// @lc code=end
