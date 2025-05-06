/*
 * @lc app=leetcode.cn id=2905 lang=golang
 *
 * [2905] 找出满足差值条件的下标 II
 */
package main

// @lc code=start
func findIndices(nums []int, indexDifference int, valueDifference int) []int {
	maxIdx, minIdx := 0, 0
	for j := indexDifference; j < len(nums); j++ {
		i := j - indexDifference
		if nums[i] > nums[maxIdx] {
			maxIdx = i
		} else if nums[i] < nums[minIdx] {
			minIdx = i
		}
		if nums[maxIdx]-nums[j] >= valueDifference {
			return []int{maxIdx, j}
		}
		if nums[j]-nums[minIdx] >= valueDifference {
			return []int{minIdx, j}
		}
	}
	return []int{-1, -1}
}

// i<j
// i-j>=idx abs(nums[i]-nums[j])>=value
// @lc code=end
