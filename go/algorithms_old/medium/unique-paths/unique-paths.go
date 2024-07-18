package algorithms

func uniquePaths(m int, n int) int {

	// You can make fixed size grid
	// grid := [100][100]int{}

	// Or you can make dynamic size grid
	grid := make([][]int, m)
	for i := 0; i < m; i++ {
		grid[i] = make([]int, n)
	}

	// Because we can only move right or down
	// So we can only have 1 way to reach all the cells in the first row
	for i := 0; i < m; i++ {
		grid[i][0] = 1
	}

	// Because we can only move right or down
	// So we can only have 1 way to reach all the cells in the first column
	for j := 0; j < n; j++ {
		grid[0][j] = 1
	}

	// For each cell lefts, we can calculate the number of ways to reach it
	// by adding the number of ways to reach the cell above and the cell left
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			grid[i][j] = grid[i-1][j] + grid[i][j-1]
		}
	}

	return grid[m-1][n-1]
}