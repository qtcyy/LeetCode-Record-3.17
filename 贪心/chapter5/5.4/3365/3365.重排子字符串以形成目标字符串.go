/*
 * @lc app=leetcode.cn id=3365 lang=golang
 *
 * [3365] 重排子字符串以形成目标字符串
 */
package main

// @lc code=start
func isPossibleToRearrange(s string, t string, k int) bool {
	n := len(s)
	div := n / k
	cnt1, cnt2 := make(map[string]int), make(map[string]int)
	for i := 0; i < n; i += div {
		var (
			tmp1 string = ""
			tmp2 string = ""
		)
		for j := i; j < i+div; j++ {
			tmp1 += string(s[j])
			tmp2 += string(t[j])
		}
		cnt1[tmp1]++
		cnt2[tmp2]++
	}
	for sub, c := range cnt1 {
		if c != cnt2[sub] {
			return false
		}
	}
	return true
}

// @lc code=end
