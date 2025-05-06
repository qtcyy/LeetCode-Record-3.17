/*
 * @lc app=leetcode.cn id=2364 lang=golang
 *
 * [2364] 统计坏数对的数目
 */
package main

import "fmt"

// @lc code=start
func countBadPairs(nums []int) int64 {
	cnt := make(map[int]int)
	cnt[nums[0]]++
	var ans int64 = 0
	for i := 1; i < len(nums); i++ {
		var cur = nums[i] - i
		ans += int64(i - cnt[cur])
		cnt[cur]++
	}

	return ans
}

// j-nums[j] != i-nums[i]
// @lc code=end
func main() {
	var nums = []int{4, 1, 3, 3}
	var ans = countBadPairs(nums)
	fmt.Println(ans)
}
