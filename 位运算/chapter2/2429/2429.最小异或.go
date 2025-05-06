/*
 * @lc app=leetcode.cn id=2429 lang=golang
 *
 * [2429] 最小异或
 */
package main

import (
	"fmt"
	"math/bits"
)

// @lc code=start
func minimizeXor(num1 int, num2 int) int {
	var c1 = bits.OnesCount(uint(num1))
	var c2 = bits.OnesCount(uint(num2))
	for ; c2 < c1; c2++ {
		num1 &= num1 - 1
	}
	for ; c1 < c2; c2-- {
		num1 |= num1 + 1
	}
	return num1
}

// @lc code=end
func main() {
	var num1, num2 = 3, 5
	var ans = minimizeXor(num1, num2)
	fmt.Println(ans)
}
