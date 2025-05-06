/*
 * @lc app=leetcode.cn id=2684 lang=golang
 *
 * [2684] 矩阵中移动的最大次数
 */
package main

// @lc code=start
var dx = []int{-1, 0, 1}
var dy = []int{1, 1, 1}

func maxMoves(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	ans, mx := 0, 0

	var dfs func(x int, y int, step int)
	dfs = func(x int, y int, step int) {
		mx = max(mx, step)
		for k := range 3 {
			tx := x + dx[k]
			ty := y + dy[k]
			if tx < 0 || tx >= n || ty < 0 || ty >= m {
				continue
			}
			if grid[tx][ty] > grid[x][y] {
				dfs(tx, ty, step+1)
			}
		}
		grid[x][y] = 0
	}
	for i := range n {
		mx = 0
		dfs(i, 0, 0)
		ans = max(ans, mx)
	}
	return ans
}

// @lc code=end
