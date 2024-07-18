package algorithms

func climbStairs(n int) int {
	if n < 2 {
		return 1
	}

	ans := make([]int,n+1)

	ans[0],ans[1] = 1,1

	// When we have a next step ans[i]
	// We can have two ways to get there
	// From all ways of ans[i-1] + 1 step
	// From all ways of ans[i-2] + 2 steps
	// So we just need to sum them
	for i := 2; i <= n; i ++ {
		ans[i] = ans[i-1] + ans[i-2]
	}

	return ans[n]
}