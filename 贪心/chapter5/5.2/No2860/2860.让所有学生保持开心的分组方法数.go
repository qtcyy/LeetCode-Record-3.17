/*
 * @lc app=leetcode.cn id=2860 lang=golang
 *
 * [2860] 让所有学生保持开心的分组方法数
 */
package main

import "slices"

// @lc code=start
func countWays(nums []int) (ans int) {
	slices.Sort(nums)
	if nums[0] > 0 {
		ans = 1
	}
	for i := 1; i < len(nums); i++ {
		if nums[i-1] < i && nums[i] > i {
			ans++
		}
	}

	return ans + 1
}

// @lc code=end
