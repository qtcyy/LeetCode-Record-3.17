/*
 * @lc app=leetcode.cn id=2914 lang=golang
 *
 * [2914] 使二进制字符串变美丽的最少修改次数
 */
package main

// @lc code=start
func minChanges(s string) (ans int) {
	n := len(s)
	for i := 0; i < n; i += 2 {
		if s[i] != s[i+1] {
			ans++
		}
	}
	return
}

// @lc code=end
