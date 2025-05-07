/*
 * @lc app=leetcode.cn id=3375 lang=golang
 *
 * [3375] 使数组的值全部为 K 的最少操作次数
 */
package main

import "slices"

// @lc code=start
func minOperations(nums []int, k int) (ans int) {
	mn := slices.Min(nums)
	if k > mn {
		ans = -1
	} else {
		s := make(map[int]int)
		for _, x := range nums {
			s[x] = 1
		}
		if k == mn {
			ans = len(s) - 1
		} else {
			ans = len(s)
		}
	}
	return
}

// @lc code=end
