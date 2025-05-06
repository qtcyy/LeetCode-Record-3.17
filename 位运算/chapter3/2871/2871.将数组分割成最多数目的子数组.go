/*
 * @lc app=leetcode.cn id=2871 lang=golang
 *
 * [2871] 将数组分割成最多数目的子数组
 */
package main

import "fmt"

// @lc code=start
func maxSubarrays(nums []int) int {
	var a = -1
	var ans = 0
	for _, x := range nums {
		a &= x
		if a == 0 {
			ans++
			a = -1
		}
	}
	return max(ans, 1)
}

// @lc code=end
func main() {
	var num = []int{1, 0, 2, 0, 1, 2}
	var ans = maxSubarrays(num)
	fmt.Println(ans)
}
