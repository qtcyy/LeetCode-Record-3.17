/*
 * @lc app=leetcode.cn id=2061 lang=golang
 *
 * [2061] 扫地机器人清扫过的空间个数
 */
package main

// @lc code=start
var dx = []int{0, 1, 0, -1}
var dy = []int{1, 0, -1, 0}

func numberOfCleanRooms(room [][]int) int {
	n, m := len(room), len(room[0])
	var dfs func(int, int, int)
	dfs = func(x, y, st int) {
		room[x][y] = 2
		tx, ty := x+dx[st], y+dy[st]
		if tx < 0 || tx >= n || ty < 0 || ty >= m {
			st = (st + 1) % 4
		}
		tx, ty = x+dx[st], y+dy[st]
		if tx < 0 || tx >= n || ty < 0 || ty >= m {
			return
		}
		if room[tx][ty] == 2 {
			return
		}
		if room[tx][ty] == 1 {
			st = (st + 1) % 4
		}
		tx, ty = x+dx[st], y+dy[st]
		if tx < 0 || tx >= n || ty < 0 || ty >= m {
			return
		}
		if room[tx][ty] == 0 {
			dfs(tx, ty, st)
		}
	}
	dfs(0, 0, 0)
	ans := 0
	for i := range n {
		for j := range m {
			if room[i][j] == 2 {
				ans++
			}
		}
	}
	return ans
}

// @lc code=end
