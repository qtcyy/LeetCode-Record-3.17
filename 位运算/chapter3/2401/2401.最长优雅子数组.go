/*
 * @lc app=leetcode.cn id=2401 lang=golang
 *
 * [2401] 最长优雅子数组
 */
package main

// @lc code=start
func longestNiceSubarray(nums []int) int {
	var ans = 1
	var left, used = 0, 0
	for i, x := range nums {
		for (used & x) != 0 {
			used ^= nums[left]
			left++
		}
		used |= x
		ans = max(ans, i-left+1)
	}
	return ans
}

// @lc code=end
