package algorithms

func minCostClimbingStairs(cost []int) int {

	l := len(cost)
	ans := make([]int, l)

	ans[0], ans[1] = cost[0], cost[1]

	for i := 2; i < l; i++ {
		// Calculate the minimum cost to reach the ith step
		ans[i] = cost[i] + min(ans[i-2], ans[i-1])
	}

	// Compare the cost to reach the last step and the cost to reach the second last step
	// and return the minimum of the two
	return min(ans[l-1],ans[l-2])
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

