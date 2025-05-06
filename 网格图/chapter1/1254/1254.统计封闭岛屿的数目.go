/*
 * @lc app=leetcode.cn id=1254 lang=golang
 *
 * [1254] 统计封闭岛屿的数目
 */
package main

// @lc code=start
func closedIsland(grid [][]int) (ans int) {
	n, m := len(grid), len(grid[0])
	if n < 3 || m < 3 {
		return
	}
	var dfs func(int, int)
	dfs = func(x, y int) {
		if x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 0 {
			return
		}
		grid[x][y] = 1
		dfs(x-1, y)
		dfs(x+1, y)
		dfs(x, y-1)
		dfs(x, y+1)
	}
	for i := 0; i < n; i++ {
		step := 1
		if 0 < i && i < n-1 {
			step = m - 1
		}
		for j := 0; j < m; j += step {
			dfs(i, j)
		}
	}
	for i := 1; i < n-1; i++ {
		for j := 1; j < m-1; j++ {
			if grid[i][j] == 0 {
				ans++
				dfs(i, j)
			}
		}
	}
	return
}

// @lc code=end
