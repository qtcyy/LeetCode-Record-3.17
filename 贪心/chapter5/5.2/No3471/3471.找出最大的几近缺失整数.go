/*
 * @lc app=leetcode.cn id=3471 lang=golang
 *
 * [3471] 找出最大的几近缺失整数
 */
package main

import "slices"

// @lc code=start
func largestInteger(nums []int, k int) int {
	// first
	n := len(nums)
	if k == n {
		return slices.Max(nums)
	} else if k == 1 {
		cnt := map[int]int{}
		for _, x := range nums {
			cnt[x]++
		}
		ans := -1
		for x, c := range cnt {
			if c == 1 {
				ans = max(ans, x)
			}
		}
		return ans
	}
	first_valid := true
	first := nums[0]
	for i := 1; i < len(nums); i++ {
		if first == nums[i] {
			first_valid = false
			break
		}
	}
	last_valid := true
	last := nums[len(nums)-1]
	for i := 0; i < len(nums)-1; i++ {
		if last == nums[i] {
			last_valid = false
			break
		}
	}
	if first_valid && last_valid {
		return max(first, last)
	} else if first_valid {
		return first
	} else if last_valid {
		return last
	} else {
		return -1
	}
}

// @lc code=end
